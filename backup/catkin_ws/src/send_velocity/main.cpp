#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h>
#include <sstream>

bool flag=true;

float translational_velocity=0.05; //0.05
float rotational_velocity=-0.1;  //0.15

int temp;
void timerCB( const ros::TimerEvent& timer){
        flag=!flag;

    ROS_INFO("Timer CB");
}


int main(int argc, char **argv)
{
    temp=0;
    ros::Timer ros_timer;




  ros::init(argc, argv, "motion_planner");


  ros::NodeHandle n;

  ros_timer = n.createTimer(ros::Duration(6),timerCB);

  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 1000);

  ros::Rate loop_rate(5);

  while (ros::ok())
  {

    geometry_msgs::Twist motion_msg;

    if(flag){
       motion_msg.linear.x=translational_velocity;
       motion_msg.angular.z=rotational_velocity;
    }
    else{
        motion_msg.linear.x=translational_velocity;
        motion_msg.angular.z=rotational_velocity*-1;
    }

    motion_msg.linear.y=0;
    motion_msg.linear.z=0;

    motion_msg.angular.x=0;
    motion_msg.angular.y=0;


    chatter_pub.publish(motion_msg);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}
