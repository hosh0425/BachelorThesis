#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>
class Trajectory{
public:
    ros::NodeHandle nh;
    ros::Publisher traj_publisher;
    Trajectory();
    float* realTrajectory(float t);
    void DFLTrajectory();

    int kp1=4;
    int kd1=3;
    int kp2=6;
    int kd2=3;
    float delta_t=0.3;

    float rd=0.2;
    float wd=2*3.1415/30;
    float U1,U2,u1,u2;

    struct pose{
        float x;
        float y;
        float theta;
    };

    struct command{
        float linear_velocity;
        float angular_velocity;
    };

    pose prevPose,nextPose;
    command prev_command;


};
