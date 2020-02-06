#include <iostream>
#include <DFL.h>

using namespace std;

int main(int argc , char* argv[]){

    ros::init(argc, argv, "switching_controller");
    DFL my_DFL;

    ros::spin();
return 0;
}
