#include "include/detectwindow.h"//

Mat DetectWindow::sub;

DetectWindow::DetectWindow(QObject *parent)
    : QObject(parent)
{


    imgenable=0;

    debug_mode=1;
    left_right_ok = 0;
    so_close = 0;
    so_close_num = 0;
    closest = false;

    avg_scale_num = 0;
    avg_scale = 70;
    for(int i=0; i<5; i++)
        avg_scale_arr[i] = 70;

    scale_brightness=150;
    output_pub = window_nh.advertise<window_node::WinDetMsg>("window_output", 1);
    image_pub=window_nh.advertise<sensor_msgs::Image>("window_image",1);


#ifdef _SPLIT_ON
    sub_mode=0;
#endif


    backprojMode = false;
    selectObject = false;
    trackObject = 0;
    showHist = true;
    vmin = 10, vmax = 256, smin = 50, erosion_size=0;
    hsize = 32;
    hranges[0] = 0;
    hranges[1] = 180;
    phranges = hranges;


    histimg = Mat::zeros(200, 320, CV_8UC3);
    paused = false;
    hist=Mat::zeros(hsize,1,CV_32F);

    //blue
    hist.at<float>(0,17)=255;
    hist.at<float>(0,18)=255;
    hist.at<float>(0,19)=255;
    hist.at<float>(0,20)=255;
    hist.at<float>(0,21)=255;
    hist.at<float>(0,22)=255;

    //    for (int i=0; i<32 ; i++)
    //    {
    //        hist.at<float>(0,i)=255;
    //    }

    scale=0;


    //#ifdef _SHOW_HIST
    //        namedWindow( "Histogram", 0 );
    //        histimg = Scalar::all(0);
    //        int binW = histimg.cols / hsize;
    //        Mat buf(1, hsize, CV_8UC3);
    //        for( int i = 0; i < hsize; i++ )
    //            buf.at<Vec3b>(i) = Vec3b(saturate_cast<uchar>(i*180./hsize), 255, 255);
    //        cvtColor(buf, buf, CV_HSV2BGR);

    //        for( int i = 0; i < hsize; i++ )
    //        {
    //            int val = saturate_cast<int>(hist.at<float>(i)*histimg.rows/255);
    //            rectangle( histimg, Point(i*binW,histimg.rows),
    //                       Point((i+1)*binW,histimg.rows - val),
    //                       Scalar(buf.at<Vec3b>(i)), -1, 8 );
    //        }
    //#endif

#ifdef _ERODE_DILATE_ON

    erosion_elem = EROSION_ELEM;
    erosion_size = EROSRION_SIZE;
    dilation_elem = DILATION_ELEM;
    dilation_size = DILATION_SIZE;
    // max_elem = 2;
    //max_kernel_size = 21;
    int erosion_type;
    if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
    else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
    else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

    ERODE_elem = getStructuringElement( erosion_type,
                                        Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                        Point( erosion_size, erosion_size ) );

    int dilation_type;
    if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
    else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
    else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

    DILATE_elem = getStructuringElement( dilation_type,
                                         Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                                         Point( dilation_size, dilation_size ) );

#endif

    connect(this, SIGNAL(imageReadySig()),this, SLOT(getImage()));


}


void DetectWindow::bubbleSort(int arr[], int n)
{

    bool swapped = true;
    int j = 0;
    int tmp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < n - j; i++) {
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;
            }
        }
    }
}

void DetectWindow::bubbleSort_point(Point arr[], int n)
{
    bool swapped = true;
    int j = 0;
    Point tmp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < n - j; i++) {
            if (arr[i].x > arr[i + 1].x) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;
            }
        }
    }
}



void DetectWindow::getImage()
{


    if (!sub.empty())
    {

        //#ifdef _SHOW_HIST
        histimg = Scalar::all(0);
        //                int binW = histimg.cols / hsize;
        //                Mat buf(1, hsize, CV_8UC3);
        //                for( int i = 0; i < hsize; i++ )
        //                    buf.at<Vec3b>(i) = Vec3b(saturate_cast<uchar>(i*180./hsize), 255, 255);
        //                cvtColor(buf, buf, CV_HSV2BGR);

        //                for( int i = 0; i < hsize; i++ )
        //                {
        //                    int val = saturate_cast<int>(hist.at<float>(i)*histimg.rows/255);
        //                    rectangle( histimg, Point(i*binW,histimg.rows),
        //                               Point((i+1)*binW,histimg.rows - val),
        //                               Scalar(buf.at<Vec3b>(i)), -1, 8 );
        //                }

        //                            imshow( "Histogram", histimg );
        //                            waitKey(1);

        //#endif

        cvtColor(sub, hsv, CV_BGR2HSV);


        int _vmin = vmin, _vmax = vmax;
        inRange(hsv, Scalar(0, smin, MIN(_vmin,_vmax)),
                Scalar(180, 256, MAX(_vmin, _vmax)), mask);
        int ch[] = {0, 0};
        hue.create(hsv.size(), hsv.depth());
        mixChannels(&hsv, 1, &hue, 1, ch, 1);

        //double exec_time5 = (double)getTickCount();
        calcBackProject(&hue, 1, 0, hist, backproj, &phranges);
        //exec_time5 = ((double)getTickCount() - exec_time5)*1000./getTickFrequency();
        // qDebug() << "       hist_time: " << exec_time5*10;
        backproj &= mask;

        int range_hsv;
        if(avg_scale > 170)
            range_hsv = 80;
        else
            range_hsv = 150;
        inRange(hsv, Scalar(0, 0, range_hsv),
                Scalar(180, 150, 256), sub_binary);




#ifdef _SMOOTH_ON
        medianBlur(backproj,backproj,3);  //change the filter
#endif

#ifdef _ERODE_DILATE_ON

        erode( backproj, backproj, ERODE_elem );
        dilate( backproj, backproj, DILATE_elem );


#endif

        //Rect border(0,0,backproj.cols,backproj.rows);
        //rectangle(backproj,border,Scalar(255,255,255),_BORDER);
        // line(backproj,Point(0,0),Point(640,0),Scalar(255,255,255),_BORDER);
        // line(backproj,Point(0,480),Point(640,480),Scalar(255,255,255),_BORDER);
        // line(backproj,Point(0,0),Point(0,480),Scalar(255,255,255),_BORDER);
        // line(backproj,Point(640,0),Point(640,480),Scalar(255,255,255),_BORDER);


        //double exec_time2 = (double)getTickCount();
#ifdef _PUBLISH
        if (imgenable==1)
        {

            firstPart=1;


            resize(backproj,backproj2,Size(320,240));

            array_to_merge.push_back(backproj2);
            array_to_merge.push_back(backproj2);
            array_to_merge.push_back(backproj2);


            merge(array_to_merge, color);
            array_to_merge.clear();

            //            imshow ("back",color);
            //            waitKey(1);

            resize(sub_binary,sub_binary2,Size(320,240));

            array_to_merge.push_back(sub_binary2);
            array_to_merge.push_back(sub_binary2);
            array_to_merge.push_back(sub_binary2);

            merge(array_to_merge, color2);
            array_to_merge.clear();

            //            imshow ("bina",color2);
            //            waitKey(1);

            sz1 = backproj2.size();
            sz2 = sub.size();
            sz3 = sub_binary2.size();
            sendFrame.create(480, 640, CV_8UC3);

            Mat left(sendFrame, Rect(0, 0, 320, 240));
            color.copyTo(left);


            Mat right(sendFrame, Rect(320, 0, 320, 240));
            color2.copyTo(right);

        }

#endif



        cv::findContours(backproj,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_NONE);

        //        qDebug() << "avg_scale :: " << avg_scale;

        output.status = 0;
        base_scale = 300;
        RotatedRect final_rotated_rect;

        for (unsigned int a=0; a < contours.size(); a++)
        {


            if (contourArea(contours[a]) < _MIN_CONTOUR_SIZE)
            {
                contours[a].clear();
                continue;
            }

            boundingjun = minAreaRect(contours[a]);

            //            qDebug() << "angle: " << boundingjun.angle;
            int angleeee = 5;
            if(!((abs(boundingjun.angle) < angleeee) || (abs(boundingjun.angle) >= (360-angleeee)) ||
                 (abs(boundingjun.angle) < (90+angleeee) && abs(boundingjun.angle) >= (90-angleeee)) ||
                 (abs(boundingjun.angle) < (180+angleeee) && abs(boundingjun.angle) >= (180-angleeee)) ||
                 (abs(boundingjun.angle) < (270+angleeee) && abs(boundingjun.angle) >= (270-angleeee))))
            {
                //                qDebug() << "WRONG angle";
                continue;
            }

            // 1. aspect ratio shouldn't be considered in high scales(2.)
            // 2. average scale for 5 times should be saved and the next rect is accepted if is in range
            // 3.

            Point2f vertices[4];
            boundingjun.points(vertices);

            ratio1_x = boundingjun.size.width / (float)boundingjun.size.height;

            if ((ratio1_x <= 1.2 && ratio1_x >= 0.8 && avg_scale < base_scale))
            {


                for(int k = 0; k < 4; k++)
                    line(sub, vertices[k], vertices[(k+1)%4], Scalar(0,0,255), 2);

                int roi_x_left,roi_y_left,roi_width=10,roi_height=10,roi_x_right,roi_y_right;
                roi_x_left=(boundingjun.center.x-boundingjun.size.width/2)-20;
                roi_y_left=boundingjun.center.y;
                roi_x_right=(boundingjun.center.x+boundingjun.size.width/2)+10;
                roi_y_right=boundingjun.center.y;

                //                if(avg_scale < base_scale)
                //                    left_right_ok = 0; // =0
                //                else
                //                    left_right_ok = 1;
                left_right_ok = 0;

                if ((roi_x_left>0 && roi_x_left<sub_binary.cols && roi_y_left>0 &&
                     (roi_y_left+roi_height)<sub_binary.rows) && left_right_ok < 2)
                {

                    Rect roi1(roi_x_left,roi_y_left,roi_width,roi_height);
                    rectangle(sub, roi1, Scalar(0,255,255),1);
                    Mat box1(sub_binary,roi1);
                    int white_count_left=countNonZero(box1);

                    if (white_count_left > (0.8*roi_width*roi_height) /*|| white_count_right>7*/)
                    {
                        if(left_right_ok == 0)
                        {
                            left_right_ok = 1;
                            //                            qDebug() << "stable left 1 *****";
                        }
                        else
                        {
                            left_right_ok = 2;
                            //                            qDebug() << "stable left 2 *****";
                        }
                    }
                    else
                    {
                        if(left_right_ok == 1)
                        {
                            //                            qDebug() << "unstable left *****";
                        }

                    }
                }
                if((roi_x_right>0 && (roi_x_right+roi_width)<sub_binary.cols &&
                    roi_y_right>0 && (roi_y_right+roi_height)<sub_binary.rows) && left_right_ok == 1)
                {
                    Rect roi2(roi_x_right,roi_y_right,roi_width,roi_height);
                    rectangle(sub, roi2, Scalar(0,255,255),1);
                    Mat box2(sub_binary,roi2);
                    int white_count_right=countNonZero(box2);

                    if (white_count_right > (0.8*roi_width*roi_height))
                    {
                        left_right_ok = 2;
                        //                        qDebug() << "stable right *****";
                    }
                    else
                    {
                        //                        qDebug() << "unstable right *****";
                    }

                } // right-white left-white

                if(left_right_ok == 2)
                {
                    for(int k = 0; k < 4; k++)
                        line(sub, vertices[k], vertices[(k+1)%4], Scalar(0,255,255), 2);

                    if (abs(last_center.x-boundingjun.center.x) < 100 &&
                            abs(last_center.y-boundingjun.center.y) < 100)
                    {
                        if(abs(boundingjun.size.width - avg_scale) < 2000)
                        {
                            //                            for(int k = 0; k < 4; k++)
                            //                                line(sub, vertices[k], vertices[(k+1)%4], (k==5)?Scalar(0,255,0):Scalar(255,0,0), 2);

                            //                            circle(sub, boundingjun.center,3, Scalar(0,255,255), 4);

                            avg_scale_arr[avg_scale_num++] = boundingjun.size.width;
                            if(avg_scale_num == 5) avg_scale_num = 0;
                            avg_scale = 0;
                            for(int p=0; p<5; p++)
                                avg_scale += avg_scale_arr[p];
                            avg_scale = avg_scale / 5;

                            if(final_rotated_rect.size.area() < boundingjun.size.area())
                                final_rotated_rect = boundingjun;

                            //                            output.delta_x=(int)boundingjun.center.x-sub.cols/2;
                            //                            output.scale=(int)boundingjun.size.width;
                            //                            output.delta_y=0;
                            output.status=255;
                            //                            qDebug() << "found";
                        }
                        else
                        {
                            //                            qDebug() << "unstable SCALE *****";
                            line(sub, last_center, boundingjun.center, Scalar(255,0,0), 2);
                        }
                    }
                    else
                    {
                        //                        qDebug() << "unstable FAR *****";
                        line(sub, last_center, boundingjun.center, Scalar(0,2,255), 2);
                    }

                    last_center.x=boundingjun.center.x;
                    last_center.y=boundingjun.center.y;
                }


            } // aspect ratio
            else if(avg_scale >= base_scale)
            {
                if(final_rotated_rect.size.area() < boundingjun.size.area())
                    final_rotated_rect = boundingjun;
                output.status=255;
                so_close++;
                //                qDebug() << "so closeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" <<
                //                                        QString::number((boundingjun.size.width > boundingjun.size.height)?
                //                                                            boundingjun.size.width:boundingjun.size.height);
            }
            //            else
            //            {
            //                for(int k = 0; k < 0; k++)
            //                    line(sub, vertices[k], vertices[(k+1)%4], Scalar(0,255,0), 2);
            //            }
        } // contour

        //        qDebug() << "----------------";

        if(output.status == 255)
        {
            Point2f vertices[4];
            final_rotated_rect.points(vertices);

            if(closest == false)
            {
                for(int k = 0; k < 4; k++)
                    line(sub, vertices[k], vertices[(k+1)%4], (k==5)?Scalar(0,255,0):Scalar(255,0,0), 2);

                circle(sub, final_rotated_rect.center,3, Scalar(0,255,255), 4);
            }

            output.delta_x = (int)final_rotated_rect.center.x-sub.cols/2;
            float scale_temp = ((int)final_rotated_rect.size.width > (int)final_rotated_rect.size.height)?
                        (int)final_rotated_rect.size.width:(int)final_rotated_rect.size.height;
            //            qDebug() << "scale: " << scale_temp;
            if(scale_temp >= 500)
            {
                output.scale = 500;
                closest = true;
            }
            else if(closest == false)
            {
                output.scale = scale_temp;
            }
            //            qDebug() << "scale:::::: " << output.scale;
            output.delta_y = 0;
            output.status = 255;


            if(so_close > 20)
            {
                if(so_close_num > 4)
                {
                    so_close_num = 0;
                    so_close = 0;
                    int roi_x_left,roi_y_left,roi_width=10,roi_height=10,roi_x_right,roi_y_right;
                    roi_x_left=(final_rotated_rect.center.x-final_rotated_rect.size.width/2)-20;
                    roi_y_left=final_rotated_rect.center.y;
                    roi_x_right=(final_rotated_rect.center.x+final_rotated_rect.size.width/2)+10;
                    roi_y_right=final_rotated_rect.center.y;
                    left_right_ok = 0;

                    if ((roi_x_left>0 && roi_x_left<sub_binary.cols && roi_y_left>0 &&
                         (roi_y_left+roi_height)<sub_binary.rows) && left_right_ok < 2)
                    {
                        left_right_ok = 1;
                    }
                    if((roi_x_right>0 && (roi_x_right+roi_width)<sub_binary.cols &&
                        roi_y_right>0 && (roi_y_right+roi_height)<sub_binary.rows) && left_right_ok == 1)
                    {
                        left_right_ok = 2;
                    } // right-white left-white

                    if(left_right_ok == 2)
                    {
                        ratio1_x = final_rotated_rect.size.width / (float)final_rotated_rect.size.height;
                        int temp_scale = ((int)final_rotated_rect.size.width > (int)final_rotated_rect.size.height)?
                                    (int)final_rotated_rect.size.width:(int)final_rotated_rect.size.height;
                        if ((ratio1_x <= 1.2 && ratio1_x >= 0.8) && (temp_scale <= (base_scale + 150)) &&
                                (temp_scale > (base_scale - 150)))
                        {
                            // correcting avg_scale
                            for(int p=0; p<5; p++)
                                avg_scale_arr[p] = base_scale - 50;
                            avg_scale = base_scale - 50;

                            closest = false;

                            Point2f vertices[4];
                            final_rotated_rect.points(vertices);

                            for(int k = 0; k < 4; k++)
                                line(sub, vertices[k], vertices[(k+1)%4], Scalar(200,0,255), 4);
                        }
                    }
                }
                so_close_num++;
            }

        }

        output_pub.publish(output);
        //            qDebug() << "scale : " << boundingjun.size.width;


#ifdef _PUBLISH
        if (imgenable==1 && firstPart==1)
        {

            //double exec_time3 = (double)getTickCount();

            //imshow ("sub",sub);
            //waitKey(1);

            resize(sub,sub,Size(640,240));

            Mat down(sendFrame, Rect(0, 240, 640, 240));
            sub.copyTo(down);

            resize(sendFrame,sendFrame,Size(320,240));

            if (!sendFrame.empty())
            {
                imageMsg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", sendFrame).toImageMsg();
                image_pub.publish(imageMsg);
            }


        }

#endif




        //        imshow("sub",sub);
        //        waitKey(1);
    }

}


DetectWindow::~DetectWindow()
{

}

void DetectWindow::imageCb_bgr(const sensor_msgs::ImageConstPtr &msg)
{
    try
    {
        sub = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8)->image;
        emit imageReadySig();

    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }

}

void DetectWindow::flightmode_Cb(const std_msgs::Int8ConstPtr& msg)
{
    qDebug() << "####################################### RESET";
    //last_x=mean_window_center=sub.cols/2;
    //isLoosing=0;
}

void DetectWindow::winSet_Cb(const window_node::WinSetMsgConstPtr &msg)
{
    qDebug() << "in winSet CB";

    if(msg->data==0)
    {
        qDebug() << "img";
        imgenable=msg->mode;
    }
    else if(msg->data==1)
    {
        qDebug() << "hist";
        hist.at<float>(0,17)=int(msg->hist_17*255);
        hist.at<float>(0,18)=int(msg->hist_18*255);
        hist.at<float>(0,19)=int(msg->hist_19*255);
        hist.at<float>(0,20)=int(msg->hist_20*255);
        hist.at<float>(0,21)=int(msg->hist_21*255);
        hist.at<float>(0,22)=int(msg->hist_22*255);
    }
    else if(msg->data==2)
    {
        qDebug() << "slider";
        smin=msg->smin;
        vmax=msg->vmax;
        vmin=msg->vmin;
#ifdef _ERODE_DILATE_ON

        dilation_elem=msg->dilation_element;
        dilation_size=msg->dilation_kernel;
        erosion_elem=msg->erosion_element;
        erosion_size=msg->erosion_kernel;
        //qDebug() << msg->erosion_element;
        int erosion_type;
        if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
        else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
        else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }
        // qDebug() << erosion_type;
        ERODE_elem = getStructuringElement( erosion_type,
                                            Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                            Point( erosion_size, erosion_size ) );

        int dilation_type;

        if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
        else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
        else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

        DILATE_elem = getStructuringElement( dilation_type,
                                             Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                                             Point( dilation_size, dilation_size ) );

#endif
    }
    else if(msg->data==3)
    {
        qDebug() << "switch";
        if(msg->swich==1)
        {
            if(fork() == 0)
            {
                // Child process will return 0 from fork()
                printf("I'm the child process.\n");
                system("rosrun marker_node marker_");
                //qDebug() << "testt                                tt"<<exec58;
                exit(0);

            }
            else
            {
                // Parent process will return a non-zero value from fork()
                printf("I'm the parent.\n");
            }
            exit(0);
        }
        else if(msg->swich==2)
        {
            exit(0);
        }
    }

    else if (msg->data==4)
    {
        qDebug() << "in reset";
        //if(msg->rst==1)
        {
            qDebug() << "####################################### ui reset!";
            // isLoosing=0;
            //last_x=mean_window_center=sub.cols/2;


        }
    }
    //    debug_mode=msg->mode;
    qDebug() << "out of winSet CB";

}




