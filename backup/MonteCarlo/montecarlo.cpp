#include "montecarlo.h"

MonteCarlo::MonteCarlo()
{
}

int MonteCarlo::DFL_tracker(Vertics start, Vertics goal){
    //srand(time(0));
    Vertics belief=start,real=start;
    float distance_error,theta_error;
    double theta_kp=0.6,distance_kp=0.02,distance_kd=0.15;
    MonteCarlo::Command outputCmd,previousCmd;
    previousCmd.v=0;
    int fault=0;

    for(int i=0;i<500;i++){
        belief=start,real=start;
        //qDebug()<<"in particle number:"<<i;
        while(distance_error=sqrt(pow(real.x-goal.x,2)+pow(real.y-goal.y,2))>0.05){
            theta_error=atan2(real.y-goal.y,real.x-goal.x)-real.theta-3.1415;

            if(theta_error>3.1415)
                theta_error=-1*(3.1415*2-theta_error);
            if(theta_error<-3.1415)
                theta_error=3.14*2+theta_error;

            double temp_angular_cmd;
            temp_angular_cmd=theta_kp*theta_error;

            outputCmd.w=temp_angular_cmd;

            if(fabs(theta_error*180/3.14)<3){
                double temp_distance_cmd=distance_error*distance_kp+distance_kd*previousCmd.v;
                if(temp_distance_cmd>0.08)
                    temp_distance_cmd=0.08;
                outputCmd.v=temp_distance_cmd;
            }
            else if(fabs(theta_error*180/3.1415)<3 && fabs(distance_error)<0.1){
                outputCmd.v=0;
                outputCmd.w=0;
            }

            previousCmd=outputCmd;
            real=realInnerStateGenerator(real,outputCmd);
//            qDebug()<<"v "<<outputCmd.v<<" "<<etaV*outputCmd.v<<" "<<outputCmd.v*randNum[i]/10<<" "<<outputCmd.v+etaV*outputCmd.v+outputCmd.v*randNum[counter]/10;
//            qDebug()<<"w "<<outputCmd.w<<" "<<etaW*outputCmd.w<<" "<<outputCmd.w*randNum[i]/10<<" "<<outputCmd.w+etaW*outputCmd.w+outputCmd.w*randNum[counter]/10;
            if(i%4==0){
            outputCmd.v=outputCmd.v+etaV*outputCmd.v+outputCmd.v*randNum[i]/20;
            outputCmd.w=outputCmd.w+etaW*outputCmd.w+outputCmd.w*randNum[i]/20;
            }
            if(i%4==1){
            outputCmd.v=outputCmd.v+etaV*outputCmd.v+outputCmd.v*randNum[i]/20;
            outputCmd.w=outputCmd.w-etaW*outputCmd.w+outputCmd.w*randNum[i]/20;
            }
            if(i%4==2){
            outputCmd.v=outputCmd.v-etaV*outputCmd.v+outputCmd.v*randNum[i]/20;
            outputCmd.w=outputCmd.w+etaW*outputCmd.w+outputCmd.w*randNum[i]/20;
            }
            if(i%4==3){
            outputCmd.v=outputCmd.v-etaV*outputCmd.v+outputCmd.v*randNum[i]/20;
            outputCmd.w=outputCmd.w-etaW*outputCmd.w+outputCmd.w*randNum[i]/20;
            }
            if(fabs(outputCmd.w)>1)//in if bara hazf kardane tasire yaw e
                //belief=belifeInnerStateGenerator(real,outputCmd);
                belief=real;
            else
                belief=belifeInnerStateGenerator(belief,outputCmd);

            int collide=checkCollision(belief);
            if(collide!=-1){
                //qDebug()<<"in particle number:"<<i<<"colide in belife move with obstacle"<<collide;
                break;
            }
            outputCmd.v=0;
            outputCmd.w=0;
        }
//        qDebug()<<"belief state"<<i<<": x:"<<belief.x<<" y:"<<belief.y<<" theta:"<<belief.theta;
//        qDebug()<<"real state"<<i<<": x:"<<real.x<<" y:"<<real.y<<" theta:"<<real.theta;

        if(sqrt(pow(belief.x-goal.x,2)+pow(belief.y-goal.y,2))>0.25){
            //qDebug()<<"error:"<<sqrt(pow(belief.x-goal.x,2)+pow(belief.y-goal.y,2));
            fault++;
        }
    }
    //qDebug()<<fault;

    return (500-fault)/5;

}

MonteCarlo::Vertics MonteCarlo::realInnerStateGenerator(Vertics start, Command action){
    Vertics nextState;
    nextState.x=start.x+action.v*cos(start.theta)*deltaT;
    nextState.y=start.y+action.v*sin(start.theta)*deltaT;
    nextState.theta=start.theta+action.w*deltaT;
//    int collide=checkCollision(nextState);
//    if(collide!=-1)
//        qDebug()<<"colide in real move";
    return nextState;
}

MonteCarlo::Vertics MonteCarlo::belifeInnerStateGenerator(Vertics start, Command action){
    Vertics nextState;
    nextState.x=start.x+action.v*cos(start.theta)*deltaT;
    nextState.y=start.y+action.v*sin(start.theta)*deltaT;
    nextState.theta=start.theta+action.w*deltaT;
//    int collide=checkCollision(nextState);
//    if(collide!=-1)
//        qDebug()<<"colide in belife move";
    return nextState;
}

int MonteCarlo::checkCollision(Vertics belife){
    for(int i=0;i<6;i++){
       // qDebug()<<"distance from"<<i<<" "<<sqrt(pow(belife.x-(obstacles[i][0]+obstacles[i][2]/2),2)+pow(belife.y-(obstacles[i][1]+obstacles[i][2]/2),2));
        if(sqrt(pow(belife.x-(obstacles[i][0]+obstacles[i][2]/2),2)+pow(belife.y-(obstacles[i][1]+obstacles[i][2]/2),2))<((obstacles[i][2]+0.09)/2))
            return i;
    }
    return -1;
}

