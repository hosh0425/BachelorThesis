/*
  Copyright (C) 2014 Parrot SA

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
  * Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in
  the documentation and/or other materials provided with the
  distribution.
  * Neither the name of Parrot nor the names
  of its contributors may be used to endorse or promote products
  derived from this software without specific prior written
  permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
  OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
  SUCH DAMAGE.
*/
/**
 * @file BebopSample.c
 * @brief This file contains sources about basic arsdk example sending commands to a bebop drone to pilot it,
 * receive its battery level and display the video stream.
 * @date 15/01/2015
 */

/*****************************************
 *
 *             include file :
 *
 *****************************************/

#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <QDebug>
#include <fstream>
#include <time.h>
#include <ctime>


extern "C"{
#include <libswscale/swscale.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libARSAL/ARSAL.h>
#include <libARController/ARController.h>
#include <libARDiscovery/ARDiscovery.h>
}

#include "main.h"
#include "ihm.h"
#define TAG "BebopSample"

#define ERROR_STR_LENGTH 2048

#define BEBOP_IP_ADDRESS "192.168.42.1"
#define BEBOP_DISCOVERY_PORT 44444


#define IHM
/*****************************************
 *
 *             private header:
 *
 ****************************************/


/*****************************************
 *
 *             implementation :
 *
 *****************************************/


#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

int gIHMRun = 1;
char gErrorStr[ERROR_STR_LENGTH];
IHM_t *ihm = NULL;

ARSAL_Sem_t stateSem;
int isBebop2 = 0;
int send_counter=0;
static void signal_handler(int signal)
{
    gIHMRun = 0;
}


ros::Publisher takeoff_pub,land_pub,cmd_vel_pub;

int main (int argc, char *argv[])
{
    ros::init(argc, argv, "Bebop2_cmd_controller");
    ros::NodeHandle n;
    takeoff_pub = n.advertise<std_msgs::Empty>("bebop/takeoff", 1000);
    land_pub = n.advertise<std_msgs::Empty>("bebop/land", 1000);
    cmd_vel_pub=n.advertise<geometry_msgs::Twist>("/bebop/cmd_vel",1000);



    ros::spinOnce();




    // local declarations
    int failed = 0;

    ARSAL_Sem_Init (&(stateSem), 0, 0);

    ARSAL_PRINT(ARSAL_PRINT_INFO, TAG, "Select your Bebop : Bebop (1) ; Bebop2 (2)");
    char answer = '1';
    scanf(" %c", &answer);
    if (answer == '2')
    {
        isBebop2 = 1;
    }

    if(isBebop2)
    {
        ARSAL_PRINT(ARSAL_PRINT_INFO, TAG, "-- Bebop 2 Sample --");
    }
    else
    {
        ARSAL_PRINT(ARSAL_PRINT_INFO, TAG, "-- Bebop Sample --");
    }


#ifdef IHM
    ihm = IHM_New (&onInputEvent);
    if (ihm != NULL)
    {
        gErrorStr[0] = '\0';
        ARSAL_Print_SetCallback (customPrintCallback); //use a custom callback to print, for not disturb ncurses IHM

        if(isBebop2)
        {
            IHM_PrintHeader (ihm, "-- Bebop 2 Sample --");
        }
        else
        {
            IHM_PrintHeader (ihm, "-- Bebop Sample --");
        }
    }
    else
    {
        ARSAL_PRINT (ARSAL_PRINT_ERROR, TAG, "Creation of IHM failed.");
        failed = 1;
    }
#endif


    if (!failed)
    {
        IHM_PrintInfo(ihm, "Running ... ('t' to takeoff ; Spacebar to land ; 'e' for emergency ; Arrow keys and ('r','f','d','g') to move ; 'q' to quit)");

#ifdef IHM
        while (gIHMRun)
        {
            usleep(50);
        }
#else
        int i = 20;
        ARSAL_PRINT(ARSAL_PRINT_INFO, TAG, "- sleep 20 ... ");
        while (gIHMRun && i--)
            sleep(1);
#endif
    }

#ifdef IHM
    IHM_Delete (&ihm);
#endif






    ARSAL_PRINT(ARSAL_PRINT_INFO, TAG, "-- END --");

    return EXIT_SUCCESS;
}

/*****************************************
 *
 *             private implementation:
 *
 ****************************************/



// IHM callbacks:

    void onInputEvent (eIHM_INPUT_EVENT event, void *customData)
    {
        std::stringstream ss;
        std_msgs::Empty empty;
        geometry_msgs::Twist twist;
        bool send_flag=false;
        switch (event)
        {
        case IHM_INPUT_EVENT_EXIT:
            IHM_PrintInfo(ihm, "IHM_INPUT_EVENT_EXIT ...");
            gIHMRun = 0;
            IHM_Delete (&ihm);
            exit(0);
            break;
        case IHM_INPUT_EVENT_EMERGENCY:
            {
               ROS_INFO("emerg");
               ss << "LAND";
               send_flag=true;
               send_counter=0;
            }
            break;
        case IHM_INPUT_EVENT_LAND:
            {
                ROS_INFO("land");
                ss << "LAND";
                send_flag=true;
                send_counter=0;
                land_pub.publish(empty);
            }
            break;
        case IHM_INPUT_EVENT_TAKEOFF:
            {
                ROS_INFO("take");
                ss<<"TAKEOFF";
                send_flag=true;
                send_counter=0;
                takeoff_pub.publish(empty);
            }
            break;
        case IHM_INPUT_EVENT_UP:
            {
                ROS_INFO("truttle");
                ss<<"UP";
                send_flag=true;
                send_counter=0;
                twist.linear.z=0.5;
                cmd_vel_pub.publish(twist);
            }
            break;
        case IHM_INPUT_EVENT_DOWN:
            {
                ROS_INFO("truttle");
                ss<<"DOWN";
                send_flag=true;
                send_counter=0;
                twist.linear.z=-0.5;
                cmd_vel_pub.publish(twist);
            }
            break;
        case IHM_INPUT_EVENT_RIGHT:
            {
                ROS_INFO("right");
                ss<<"RIGHT";
                send_flag=true;
                send_counter=0;
                twist.angular.z=-0.5;
                cmd_vel_pub.publish(twist);
            }
            break;
        case IHM_INPUT_EVENT_LEFT:
            {
                ROS_INFO("left");
                ss<<"LEFT";
                send_flag=true;
                send_counter=0;
                twist.angular.z=0.5;
                cmd_vel_pub.publish(twist);
            }
            break;
        case IHM_INPUT_EVENT_FORWARD:
            {
                ROS_INFO("fwd");
                ss<<"FORWARD";
                send_flag=true;
                send_counter=0;
                twist.linear.x=0.5;
                cmd_vel_pub.publish(twist);
            }
            break;
        case IHM_INPUT_EVENT_BACK:
            {
                ROS_INFO("back");
                ss<<"BACK";
                send_flag=true;
                send_counter=0;
                twist.linear.x=-0.5;
                cmd_vel_pub.publish(twist);
            }
            break;
        case IHM_INPUT_EVENT_ROLL_LEFT:
            {
                ROS_INFO("roll");
                ss<<"ROLLLEFT";
                send_flag=true;
                send_counter=0;
                twist.linear.y=0.5;
                cmd_vel_pub.publish(twist);
            }
            break;
        case IHM_INPUT_EVENT_ROLL_RIGHT:
            {
                ROS_INFO("roll");
                ss<<"ROLLRIGHT";
                send_flag=true;
                send_counter=0;
                twist.linear.y=-0.5;
                cmd_vel_pub.publish(twist);
            }
            break;
        case IHM_INPUT_EVENT_NONE:
            {
               usleep(5);
               ss<<"NONE";
               send_flag=false;
               send_counter++;
               if(send_counter==1)
                cmd_vel_pub.publish(twist);
            }
            break;
        default:
            break;
        }



    }



int customPrintCallback (eARSAL_PRINT_LEVEL level, const char *tag, const char *format, va_list va)
{
    // Custom callback used when ncurses is runing for not disturb the IHM

    if ((level == ARSAL_PRINT_ERROR) && (strcmp(TAG, tag) == 0))
    {
        // Save the last Error
        vsnprintf(gErrorStr, (ERROR_STR_LENGTH - 1), format, va);
        gErrorStr[ERROR_STR_LENGTH - 1] = '\0';
    }

    return 1;
}
