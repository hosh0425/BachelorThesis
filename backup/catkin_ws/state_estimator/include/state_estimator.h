#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <state_estimator/Ardrone3PilotingStateSpeedChanged.h>
#include <state_estimator/Ardrone3PilotingStateAttitudeChanged.h>
#include <math.h>

#include <QFile>
#include <QTextStream>



//#define delta_t 0.2
#define linear_velocity_noise 5
#define angular_velocity_noise 2

#define alpha_1     0.1
#define alpha_2     0.05
#define alpha_3     0.05
#define alpha_4     0.05

#define range_variance      0.30
#define beam_variance       0.1

class EKF{
public:

    ros::NodeHandle nh;
    ros::Subscriber observation_sub;
    ros::Subscriber linear_velocity_sub;
    ros::Subscriber attitude_sub;
    ros::Publisher position;

    double delta_t;
    struct blief{
        float mean[3];
        float covariance[3][3];
    };


    struct motion_cmd{
        //value of this two variable will change in motion_command call back
        float translational_velocity , rotational_velocity;
        float previouse_yaw;
        uint32_t previouse_time;
    };


    struct observation{
        //value of this three variable will change in observation call back
        float observation_range_x,observation_range_y , observation_beam;
        int marker_id;
    };

    blief prev_position , predicted_position;
    motion_cmd recieved_motion_cmd;
    observation recieved_observation[10];
    int number_of_observation,recursive_num_of_observation;


    ros::Time begin,end;


    QFile *my_file;
    QString file_name="/home/hossein/Desktop/sec_ekf_log1.txt";
    QTextStream *out;
    QString first_str,second_str,third_str;

    float rand_v_noise,rand_omega_noise;


    //changed : 80
    float marker_pose[85][2]={{3,0},{3.05 ,-0.882451},{3.05 ,-2.11831},{3.05, -3.1257},{2 ,-4.29},{1.02289, -4.29},{0.016929 ,-4.29},{-0.988321, -4.29},{-1.98317 ,-4.29}
                              ,{-2.14 ,-4.1324},{-2.14 ,-3.13559},{-2.14 ,-2.12866},{-2.14 ,-1.1333},{-2.14 ,-0.116922},{-2.14 ,0.873925},{-2.14 ,1.87713},{-2.14 ,2.96}
                              ,{-1.97987 ,3.5},{-0.975307 ,3.5},{0.011529 ,3.5},{1.03378 ,3.5},{2.03024 ,3.5},{3.05, 1.87091},{3.05 ,0.889399},{3.05,2.96},{1.1,-1.09},
                              {1.11,1.47},{0,-2.84},{-0.97,-2.06},{-0.83,0.63}
                             };





    EKF();

    void observation_callback(const geometry_msgs::TwistConstPtr &observation_msg);

    void linear_velocity_callback(state_estimator::Ardrone3PilotingStateSpeedChanged linear_velocity_command);
    void attitude_callback(state_estimator::Ardrone3PilotingStateAttitudeChanged attitude_command);



    void  state_estimator(); //const ros::TimerEvent& timer

    float** matrix_transpose_3(float  matrix[][3]);
    float** matrix_transpose_2(float  matrix[][2]);
    float** matrix_transpose_1(float  matrix[][3]);

    float** mult_line_7_step_one(float matrix_1[][3],float** matrix_2);
    float** mult_line_7_step_two(float matrix_1[][2],float matrix_2[][2],float **matrix_3);
    float** mult_line_14(float matrix_1[][3],float** matrix_2);
    float** mat_inverse(float matrix [][2]);
    float** mult_line_15(float** matrix_1,float** matrix_2);
    float** mult_line_16(float** matrix_1,float matrix_2[2]);
    float** mult_line_17(float** matrix_1,float matrix_2[][3]);
    float** mult_line_17_b(float** matrix_1);


    float range;

    float truth=-1.3;
    int repeat=0;
    ros::Timer ros_timer;





};
