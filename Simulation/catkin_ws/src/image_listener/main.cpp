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


class image_listener
{
public:

    Mat cameraMatrix;
    Mat distCoeffs;
    Mat imageCopy;

    image_listener() {
        cameraMatrix = Mat(3, 3, CV_32FC1);
        distCoeffs = Mat(1, 5, CV_32FC1);

        cameraMatrix.ptr<float>(0)[0] = 563.347731f;   // fx
        cameraMatrix.ptr<float>(0)[1] = 0.000000f;     // 0
        cameraMatrix.ptr<float>(0)[2] = 444.311477f;   // cx
        cameraMatrix.ptr<float>(1)[0] = 0.000000f;     // 0
        cameraMatrix.ptr<float>(1)[1] = 551.527835f;    // fy
        cameraMatrix.ptr<float>(1)[2] = 225.534341f;    // cy
        cameraMatrix.ptr<float>(2)[0] = 0.000000f;     // 0
        cameraMatrix.ptr<float>(2)[1] = 0.000000f;     // 0
        cameraMatrix.ptr<float>(2)[2] = 1.000000f;     // 1

        distCoeffs.ptr<float>(0)[0] = 0.022182;         // k1
        distCoeffs.ptr<float>(0)[1] = 0.010401;         // k2
        distCoeffs.ptr<float>(0)[2] =-0.008768;         // p1
        distCoeffs.ptr<float>(0)[3] = 0.004915;         // p2
        distCoeffs.ptr<float>(0)[4] = 0.0;              // k2


        image_transport::ImageTransport it(nh);
        sub = it.subscribe("/bebop/image_raw", 1, &image_listener::imageCallback,this);
        aruko_pub=nh.advertise<geometry_msgs::Twist>("observation",100);

    }


    ros::NodeHandle nh;
    image_transport::Subscriber sub;
    ros::Publisher aruko_pub;



    void imageCallback(const sensor_msgs::ImageConstPtr& msg)
    {

        geometry_msgs::Twist aruko_msg;

        cv_bridge::CvImageConstPtr cv_ptr;

        try
        {
            cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::BGR8);

        }
        catch (cv_bridge::Exception& e)
        {
            ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
        }

        cv::Mat image;
        cv_ptr->image.copyTo(image);
        image.copyTo(imageCopy);

        std::vector<int> ids;
        std::vector<std::vector<cv::Point2f> > corners;
        cv::aruco::detectMarkers(image, cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250), corners, ids);


        // if at least one marker detected
        if (ids.size() > 0) {

            vector< Vec3d > rvecs, tvecs;
            cv::aruco::estimatePoseSingleMarkers(corners, 0.13, cameraMatrix, distCoeffs, rvecs, tvecs); // draw axis for each marker
            for(int i=0; i<ids.size(); i++){
                float distance=sqrt(tvecs[i][0]*tvecs[i][0]+tvecs[i][2]*tvecs[i][2]);
                //ROS_INFO("id: %d  %f    %f     %f  dist:%f",ids[i], tvecs[i][0],tvecs[i][1],tvecs[i][2],distance);

                if(true){ //distance>0.3 && distance<3.2 && abs(rvecs[i][0])<0.05 fagat 30cm ta 3m va ba zaviyeye kam ghaboole  //&& abs(rvecs[i][0])<0.04
                    ROS_INFO("marker:%d   %f    %f     %f  dist:%f",ids[i], tvecs[i][0],tvecs[i][1],tvecs[i][2],distance);
                    //ROS_INFO("%f    %f     %f  ", rvecs[i][0],rvecs[i][1],rvecs[i][2]);

                    aruko_msg.linear.y=tvecs[i][0];
                    aruko_msg.linear.z=ids[i];
                    aruko_msg.linear.x=tvecs[i][2];

                    aruko_msg.angular.y=rvecs[i][0];
                    aruko_msg.angular.z=rvecs[i][1];
                    aruko_msg.angular.x=rvecs[i][2];
                    aruko_pub.publish(aruko_msg);
                    cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
                    cv::aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], 0.1);
                }

            }
        }

        cv::imshow("outt", imageCopy);
        waitKey(1);
    }


};


int main(int argc, char **argv){

    ros::init(argc, argv, "image_listener");
    image_listener listen;
    ros::spin();


    return 0;

}


