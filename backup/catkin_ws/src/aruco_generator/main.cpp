#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <geometry_msgs/Twist.h>
#include <cv_bridge/cv_bridge.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/aruco/charuco.hpp>
#include <opencv2/aruco/dictionary.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>

#include <iostream>


using namespace  cv;
using namespace std;


int main(int argc, char **argv){

    ros::init(argc, argv, "aruco_generator");
    cv::Mat markerImage;
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    char buffer[100];
    for(int i=1;i<99;i++){
        //output marker will be 200*200
        cv::aruco::drawMarker(dictionary, i, 200, markerImage, 1);
        sprintf (buffer, "/home/hossein/Desktop/marker/marker%d.png",i);
        cv::imwrite(buffer,markerImage);
    }

    return 0;

}


