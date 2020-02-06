#include <algorithm>
#include <iostream>
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/opencv.hpp>
#include <QObject>
#include <QThread>
#include <QApplication>
#include "include/detectwindow.h"


int main(int argc, char** argv)
{
    QApplication a(argc, argv);

    ros::init(argc, argv, "window_node");

    ros::NodeHandle nh_;
    image_transport::ImageTransport it(nh_);
    image_transport::Subscriber rgb_image_sub_;
    ros::Subscriber win_set;
    ros::Subscriber flightMode;

    DetectWindow win;

    // Subscribe to input video feed for grab rgb and publish output video feed
    rgb_image_sub_ = it.subscribe("	", 1,
                                  &DetectWindow::imageCb_bgr, &win);

    win_set = nh_.subscribe("winset_output", 1,
                            &DetectWindow::winSet_Cb, &win);

    flightMode = nh_.subscribe("flight_mode", 1,
                            &DetectWindow::flightmode_Cb, &win);

    ros::spin();
    return 0;
    //return a.exec();
}

