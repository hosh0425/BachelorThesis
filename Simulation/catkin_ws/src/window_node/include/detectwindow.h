 #ifndef DETECTWINDOW_H
#define DETECTWINDOW_H

#ifndef Q_MOC_RUN
#include <QDebug>
#include <opencv/cv.h>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QDate>
#include <QTime>
#include <iostream>
#include <ctype.h>
#include "ros/ros.h"
#include <std_msgs/Int8.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <sstream>
#include <window_node/WinDetMsg.h>
#include <window_node/WinSetMsg.h>
#include <QTimer>
#endif
using namespace cv;
using namespace std;

#define _MIN_CONTOUR_SIZE   800

#define EROSION_ELEM    0
#define EROSRION_SIZE   1
#define DILATION_ELEM   0
#define DILATION_SIZE   3

//#define _SHOW_HIST
#define _ERODE_DILATE_ON
//#define _SMOOTH_ON
#define _PUBLISH



class DetectWindow : public QObject
{
    Q_OBJECT

public:
    DetectWindow(QObject *parent = 0);
    ~DetectWindow();

    void imageCb_bgr(const sensor_msgs::ImageConstPtr& msg);
    void winSet_Cb(const window_node::WinSetMsgConstPtr& msg);
    void flightmode_Cb(const std_msgs::Int8ConstPtr& msg);

    void bubbleSort(int arr[], int n);
    void bubbleSort_point(Point arr[], int n);

    window_node::WinDetMsg output;
    ros::Publisher output_pub;
    ros::Publisher output_depth_pub;
    ros::Publisher image_pub;
    ros::NodeHandle window_nh;
    sensor_msgs::ImagePtr imageMsg;

    Mat frame;
    Mat image,edges,image_bordered;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    //vector<Point> approxCurve[100];
//    int contour_cols_size[100];
//    int window_num[100];
//    int two_num;
//    int three_window_num_border[100];
//    Point window_center;
//    Point two_win_center_one;
//    Point two_win_center_two;
//    Point three_windows_center[3];
//    Point three_windows_center_sorted[3];
//    int left_border, right_border, middle, middle_ratio;
//    int three_windows_x[3];
//    int mean_window_center;
//    int last_x;

    bool backprojMode;
    bool selectObject;
    int trackObject;
    bool showHist;
    Point origin;
    Rect selection;
    int vmin, vmax, smin;

    QDate CurrDate;
    QTime CurrTime;
    VideoWriter CamOut;
    QString ImgPath,ImgPath2,CurrDateText,CurrTimeText,path,path_img;

    int hsize;
    float hranges[2];
    const float* phranges;

    Mat hsv, hue, mask, hist, histimg , backproj ,backproj_blured , white_mask ,backproj2 , sub_binary2;
    bool paused;

    bool show;
    int sub_mode;
    Rect roi;
    static Mat sub;
    Mat sub_gray,sub_binary;

    Mat erosion_dst, dilation_dst, ERODE_elem, DILATE_elem;
    Mat detectFrame;

    std::vector<cv::Mat> array_to_merge;
    cv::Mat color,color2;
    Mat sendFrame;
    Size sz1;
    Size sz2;
    Size sz3;
    bool reset_flag;

    int erosion_elem;
    int erosion_size;
    int dilation_elem;
    int dilation_size;

    int side1_y,side2_y,side1_x,side2_x,scale;
    float ratio1_y,ratio2_y,ratio1_x,ratio2_x, base_scale;
//    int hit_border;
//    int two_win_num[2];
//    int inside_polygons;
    //int const max_elem;
    //int const max_kernel_size;
//    bool depth_flag;
    bool debug_mode;
    int imgenable;
    bool firstPart;
//    int isLoosing;
    int reset_count;
    int scale_brightness;

   // QTimer *test_timer;
    VideoCapture cap;
    int last_scale;
    Point2f last_center;
    RotatedRect boundingjun;

    int so_close, so_close_num;
    bool closest;

    int left_right_ok, avg_scale_num;
    float avg_scale_arr[5], avg_scale;


public slots:
    void getImage();
   // void timerEvent();


signals:
    void dataReady();
    void imageReadySig();

};

#endif // DETECTWINDOW_H


