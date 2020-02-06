#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>

#include <QTextStream>
#include <QFile>


#define linear_velocity_noise 5
#define angular_velocity_noise 2

#define destination_x      1.7
#define destination_y      1.9
#define destination_theta  1.7
#define pathPlaningResultPointsSize 7


#define linear_velocity_max     0.08
#define angular_velocity_max    0.6

#define KP1  0.3//0.8//0.33
#define KP2  0.3//1.49//1.5
#define Kd1  0.4//2//2
#define Kd2  0.4//2.6//3

class DFL{
public:

    ros::NodeHandle nh;
    ros::Subscriber EKF_sub;
    ros::Publisher  DFL_out;

    double delta_t,previouse_time;
    int enterance_to_switching_controller=0;


    struct pose{
        float x;
        float y;
        float linear_velocity;
        float theta;
    };

    struct command{
        float linear_velocity;
        float angular_velocity;
    };

    pose subscribed_pose;
    command prev_command;

    DFL();
    geometry_msgs::Twist command_output; //for P controller

    pose compute_distance_for_control(pose belief);

    void EKF_callback(const geometry_msgs::TwistConstPtr &observation_msg);

    void  DFL_controller(pose belief);
    void  P_controller(pose belief);

    struct point{
        float x;
        float y;
        float theta;
    };
    point destination;
    int pathPlaningResultPoints[pathPlaningResultPointsSize]={9,10,8,7,15,18,17};//9,10,8,7,15,18,17

    float points[28][3]={{2.6,3,1.2},{2.8,1.2,0.7},{1.7,1.9,1.7},{1,2.9,-2},{0.4,1.2,0.3},//badi 5
                         {1.3,0.8,-0.9},{2.9,0,1},{1.7,-0.7,-2},{2.7,-2,-0.5},{2.8,-4,0.6} //badi10
                         ,{2.2,-3.2,2.5},{0.7,-0.8,0.5},{1,-2.2,-0.3},{0,-3.2,-3},{-0.7,-1.8,2.9},//badi15
                         {0,0,-0.7},{1.5,-4,1.7},{-1.5,-2,-0.9},{-1.2,-0.8,-2.2},{-0.8,0.8,0.8},//badi20
                         {-0.6,1.5,2.5},{-1.2,3,1},{-2,2.7,1.9},{-1.5,1.2,-2},{-1.9,0.1,-3},//badi25
                         {-1.5,-3.5,3},{-0.5,2.5,0.2},{-1,3,0.9}};

    int counter=0;
    QFile *my_file;
    QString file_name="/home/hossein/Desktop/sec_motion_log1.txt";
    QTextStream *out;
    QString first_str,second_str,third_str,fourth_str;
};
