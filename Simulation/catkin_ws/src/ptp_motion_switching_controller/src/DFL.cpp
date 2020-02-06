#include <DFL.h>

DFL::DFL(){
    EKF_sub=nh.subscribe("/position",1,&DFL::EKF_callback,this);
    DFL_out=nh.advertise<geometry_msgs::Twist>("/bebop/cmd_vel",10);

    prev_command.linear_velocity=prev_command.angular_velocity=0;
    previouse_time=ros::Time::now().toNSec();

    my_file=new QFile(file_name);
    my_file->open(QFile::WriteOnly |QFile::Text);
    out=new QTextStream(my_file);

    destination.x=points[pathPlaningResultPoints[1]][0];
    destination.y=points[pathPlaningResultPoints[1]][1];
    destination.theta=points[pathPlaningResultPoints[1]][2];
}

int stabilityCounter=0;
int pathCounter=2;
bool first_step=true;
bool second_step=false;
void DFL::EKF_callback(const geometry_msgs::TwistConstPtr &observation_msg){
    subscribed_pose.x=observation_msg->linear.x;
    subscribed_pose.y=observation_msg->linear.y;
    subscribed_pose.linear_velocity=observation_msg->linear.z;
    subscribed_pose.theta=observation_msg->angular.z;
    double now_time=ros::Time::now().toNSec();
    delta_t=(now_time-previouse_time)/1000000000;
    if(delta_t>0.5)
        ROS_ERROR("bad delta_t: %f",delta_t);
    previouse_time=now_time;
    ROS_INFO("delta_t : %f",delta_t);
    //DFL_controller(subscribed_pose);
    if(stabilityCounter>30){
        ROS_WARN("change destination");
        destination.x=points[pathPlaningResultPoints[pathCounter]][0];
        destination.y=points[pathPlaningResultPoints[pathCounter]][1];
        destination.theta=points[pathPlaningResultPoints[pathCounter++]][2];
        stabilityCounter=0;
        first_step=true;
        second_step=false;
    }

    if((pathCounter)==pathPlaningResultPointsSize+1){
        ROS_INFO("mission complete :D");
        exit(0);
    }
    P_controller(subscribed_pose);

}



double theta_kp=0.5,distance_kp=0.03,distance_kd=0.15; //theta_kp=0.6,distance_kp=0.02,distance_kd=0.15;
double theta_error,distance_error;
void DFL::P_controller(pose belief){
    /*
     * marhaleye aval bayad darjahate destination gharar begirim ta mostaghim berim
     */
    distance_error=sqrt(pow(belief.x-destination.x,2)+pow(belief.y-destination.y,2));

    if(distance_error>0.05)
        theta_error=atan2(belief.y-destination.y,belief.x-destination.x)-belief.theta-3.1415;
    else{
        theta_error=0;
        first_step=false;
        second_step=true;
    }

    if(theta_error>3.1415)
        theta_error=-1*(3.1415*2-theta_error);
    if(theta_error<-3.1415)
        theta_error=3.14*2+theta_error;



    if (first_step) {

        //ROS_INFO("desired theta: %f belife theta: %f",theta_error*180/3.14,belief.theta*180/3.14);
        double temp_angular_cmd;
        temp_angular_cmd=theta_kp*theta_error;


        command_output.angular.z=temp_angular_cmd;

        if(fabs(theta_error*180/3.14)<2){
            double temp_distance_cmd=distance_error*distance_kp+distance_kd*belief.linear_velocity;
           // ROS_INFO("linear vel output: %f, P:%f , D:%f",temp_distance_cmd,distance_error*distance_kp,distance_kd*belief.linear_velocity);
            if(temp_distance_cmd>0.08)
                temp_distance_cmd=0.08;
            command_output.linear.x=temp_distance_cmd;
        }
        else if(fabs(theta_error*180/3.1415)<3 && fabs(distance_error)<0.1){
            command_output.linear.x=0;
            command_output.angular.z=0;
        }

        DFL_out.publish(command_output);
        ROS_INFO("theta error: %f Distance error: %f",theta_error,distance_error);


    }
    if(second_step){
        ROS_INFO("yaw correction");
        pose oldPose=compute_distance_for_control(belief);
        command_output.linear.x=0;
        command_output.angular.z=1.3*tanh(-oldPose.theta);
        stabilityCounter++;
        DFL_out.publish(command_output);


        //ROS_INFO("translation velocity Out: %f",temp_distance_cmd);

    }
}

void DFL::DFL_controller(pose belief){

    command old_cmd;
    old_cmd.linear_velocity=prev_command.linear_velocity;
    old_cmd.angular_velocity=prev_command.angular_velocity;

    pose old_pose_tmp=compute_distance_for_control(belief);
    pose old_pose;
    old_pose.x=old_pose_tmp.x*cos(destination.theta)+old_pose_tmp.y*sin(destination.theta);
    old_pose.y=-old_pose_tmp.x*sin(destination.theta)+old_pose_tmp.y*cos(destination.theta);
    old_pose.theta=old_pose_tmp.theta;

    ROS_INFO("distance error:x=%f    y=%f",old_pose.x,old_pose.y);
    float x_der=belief.linear_velocity*cos(old_pose.theta);//old_cmd.linear_velocity*cos(old_pose.theta);
    float y_der=belief.linear_velocity*sin(old_pose.theta);//old_cmd.linear_velocity*sin(old_pose.theta);

    float U1=-KP1*old_pose.x-Kd1*x_der;
    float U2=-KP2*old_pose.y-Kd2*y_der;

    command next_cmd;
    next_cmd.linear_velocity=old_cmd.linear_velocity+(U1*cos(old_pose.theta)+U2*sin(old_pose.theta))*delta_t;
    //    if(next_cmd.linear_velocity<0.0005){
    //        next_cmd.angular_velocity=0;
    //        //enterance_to_switching_controller=3; //in darsooratiye ke faghat ye harekat dashte bashe age gharare chandta masire motavali bere in nemizare
    //    }
    //    else
    next_cmd.angular_velocity=((U2*cos(old_pose.theta))-(U1*sin(old_pose.theta)));///next_cmd.linear_velocity;;
    //next_cmd.angular_velocity=((U2*cos(old_pose.theta))-(U1*sin(old_pose.theta)))/next_cmd.linear_velocity; asli ine





    if(next_cmd.linear_velocity>linear_velocity_max)
        next_cmd.linear_velocity=linear_velocity_max;
    if(next_cmd.angular_velocity>angular_velocity_max)
        next_cmd.angular_velocity=angular_velocity_max;


    if(next_cmd.linear_velocity<0) //dande aghab nadarim
        next_cmd.linear_velocity=0;
    if(next_cmd.angular_velocity<-angular_velocity_max) //vali omegaye manfi darim
        next_cmd.angular_velocity=-angular_velocity_max;



    if(sqrt(old_pose.x*old_pose.x+old_pose.y*old_pose.y)<0.20)
        enterance_to_switching_controller=3; //baraye avalin bar varede oon nahiye shod ke bayad berim soraghe kelid zani

    //age ye bar varede kelid zani shod toosh bemoone hadeaghal 3bar
    if(enterance_to_switching_controller>0){
        if(fabs(old_pose.theta-destination.theta))
            next_cmd.linear_velocity=0;
        next_cmd.angular_velocity=1.3*tanh(-old_pose.theta);
        if(next_cmd.angular_velocity>angular_velocity_max)
            next_cmd.angular_velocity=angular_velocity_max;
        if(next_cmd.angular_velocity<-angular_velocity_max)
            next_cmd.angular_velocity=-angular_velocity_max;

        ROS_WARN("in heading angle controller");
        enterance_to_switching_controller--;
    }
    counter++;

    geometry_msgs::Twist command_output;
    command_output.linear.x=next_cmd.linear_velocity;
    command_output.angular.z=next_cmd.angular_velocity;

    ROS_INFO("output command:  v=%f    w: %f",next_cmd.linear_velocity,next_cmd.angular_velocity);
    DFL_out.publish(command_output);

    prev_command.linear_velocity=next_cmd.linear_velocity;
    prev_command.angular_velocity=next_cmd.angular_velocity;

    first_str.setNum(next_cmd.linear_velocity);
    second_str.setNum(next_cmd.angular_velocity);
    *out<<first_str<<"       "<<second_str<<"\n";
    my_file->flush();

    if(counter==500){
        my_file->close();
        ROS_INFO("file closed");
        exit(0);
    }




}



DFL::pose DFL::compute_distance_for_control(pose belief){
    pose resault;
    resault.x=belief.x-destination.x;
    resault.y=belief.y-destination.y;
    resault.theta=belief.theta-destination.theta;

    float modified_theta=resault.theta;
    float modified_theta_bounded;

    if(modified_theta>=0){
        modified_theta_bounded=fmod(modified_theta,2*3.1415);
        if(modified_theta_bounded>3.1415) //floating point remainder
            modified_theta_bounded-=2*3.1415;
    }
    else{
        modified_theta_bounded=-fmod(-modified_theta,2*3.1415);
        if(modified_theta_bounded<-3.1415)
            modified_theta_bounded+=2*3.1415;
    }

    resault.theta=modified_theta_bounded;

    return resault;
}
