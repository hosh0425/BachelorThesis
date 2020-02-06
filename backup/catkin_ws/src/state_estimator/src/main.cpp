#include <state_estimator.h>

using namespace std;
using namespace ros;


int main(int argc, char *argv[]){
    ros::init(argc, argv, "ekf");
    EKF my_EKF;

    ros::spin();

return 0;
}
