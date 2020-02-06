#include <trajectory.h>

Trajectory::Trajectory(){
    traj_publisher=nh.advertise<geometry_msgs::Twist>("/bebop/cmd_vel",10);

    DFLTrajectory();
}

void Trajectory::DFLTrajectory(){
    float timeStep;

    U1=0;
    U2=0;

    float prevVx=0;
    float prevVy=0;
    float prevV=0;
    float prevW=0;
    float nextV=0;
    float nextW=0;
    float delta_t;

    for(int i=0;i<100;i++){
        usleep(300000);
        timeStep+=delta_t;
        float *real=realTrajectory(timeStep);
        float xr=real[0];
        float yr=real[1];
        float thr=real[2];
        u1=kp1*(xr-prevPose.x)+kd1*(real[3]-prevVx);
        u2=kp2*(yr-prevPose.y)+kd2*(real[4]-prevVy);
        ROS_INFO("u1: %f  u2: %f",u1,u2);
        nextV=prevV+(u1*cos(prevPose.theta)+u2*sin(prevPose.theta))*delta_t;
        nextW=((u1*cos(prevPose.theta))-(u2*sin(prevPose.theta)))/nextV;

        if(fabs(nextV)>0.2)
            nextV=0.2;
        if(nextW>5)
            nextW=5;
        if(nextW<-5)
            nextW=-5;

        geometry_msgs::Twist command_output;
        command_output.linear.x=nextV;
        command_output.angular.z=nextW;

        traj_publisher.publish(command_output);
        ROS_INFO("V: %f  W: %f",nextV,nextW);

        nextPose.x=prevPose.x+delta_t*nextV*cos(prevPose.theta);
        nextPose.y=prevPose.y+delta_t*nextV*sin(prevPose.theta);
        nextPose.theta=prevPose.theta+delta_t*nextW;
        prevVx=nextV*cos(nextPose.theta);
        prevVy=nextV*sin(nextPose.theta);
        prevPose.x=nextPose.x;
        prevPose.y=nextPose.y;
        prevPose.theta=nextPose.theta;
        U1=u1;
        U2=u2;

    }
}

float* Trajectory::realTrajectory(float t){
    float* output=new float[9];
    float x=1+rd*sin(wd*t);
    float y=1-rd*cos(wd*t);
    float vx=rd*wd*cos(wd*t);
    float vy=rd*wd*sin(wd*t);
    float ax=-rd*wd*sin(wd*t);
    float ay=rd*wd*cos(wd*t);
    float th=wd*t;
    float vd=rd*wd;


    output[0]=x;
    output[1]=y;
    output[2]=th;
    output[3]=vx;
    output[4]=vy;
    output[5]=ax;
    output[6]=ay;
    output[7]=vd;
    output[8]=wd;
    return output;
}
