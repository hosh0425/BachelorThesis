#include "mdp.h"

MDP::MDP()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++){
            valueNorth[i][j]=valueEast[i][j]=valueSouth[i][j]=valueWest[i][j]=0;
            preValueNorth[i][j]=prevValueEast[i][j]=prevValueSouth[i][j]=0;prevValueWest[i][j]=0;
        }

    preValueNorth[0][3]=prevValueEast[0][3]=prevValueSouth[0][3]=prevValueWest[0][3]=1;
    valueNorth[0][3]=valueEast[0][3]=valueSouth[0][3]=valueWest[0][3]=1;

    preValueNorth[1][3]=prevValueEast[1][3]=prevValueSouth[1][3]=prevValueWest[1][3]=-1;
    valueNorth[1][3]=valueEast[1][3]=valueSouth[1][3]=valueWest[1][3]=-1;

}

void MDP::optimalValueFunction(){

    double tempValue1;
    double* transitions;
    float maxValue;
    for(int i=0;i<1000;i++){

        //for ActionNorth
        for(int m=0;m<3;m++){
            for(int k=0;k<4;k++){

                if((m==1 && k==1) || (m==0 && k==3) || (m==1 && k==3))
                    continue;
                transitions=possibleTransition(m,k,ActionNorth);
//                qDebug()<<" ";
//                qDebug()<<"position: "<<m<<" "<<k;
//                qDebug()<<"position: "<<transitions[0]<<" "<<transitions[1]<<" possibility:"<<transitions[2];
//                qDebug()<<"position: "<<transitions[3]<<" "<<transitions[4]<<" possibility:"<<transitions[5];
//                qDebug()<<"position: "<<transitions[6]<<" "<<transitions[7]<<" possibility:"<<transitions[8];
                maxValue=maximum(preValueNorth[(int)transitions[0]][(int)transitions[1]],prevValueEast[(int)transitions[0]][(int)transitions[1]]
                        ,prevValueSouth[(int)transitions[0]][(int)transitions[1]],prevValueWest[(int)transitions[0]][(int)transitions[1]]);
                tempValue1=discountFactor*(maxValue*transitions[2]);

                maxValue=maximum(preValueNorth[(int)transitions[3]][(int)transitions[4]],prevValueEast[(int)transitions[3]][(int)transitions[4]]
                        ,prevValueSouth[(int)transitions[3]][(int)transitions[4]],prevValueWest[(int)transitions[3]][(int)transitions[4]]);
                tempValue1+=discountFactor*(maxValue*transitions[5]);

                maxValue=maximum(preValueNorth[(int)transitions[6]][(int)transitions[7]],prevValueEast[(int)transitions[6]][(int)transitions[7]]
                        ,prevValueSouth[(int)transitions[6]][(int)transitions[7]],prevValueWest[(int)transitions[6]][(int)transitions[7]]);
                tempValue1+=discountFactor*(maxValue*transitions[8]);
                valueNorth[m][k]=tempValue1+reward[m][k];

               // qDebug()<<"value: "<<valueNorth[m][k];
            }
        }

        //for ActionEast
        for(int m=0;m<3;m++){
            for(int k=0;k<4;k++){
                if((m==1 && k==1) || (m==0 && k==3) || (m==1 && k==3))
                    continue;
                //                qDebug()<<"position: "<<m<<" "<<k;
                transitions=possibleTransition(m,k,ActionEast);
                //                qDebug()<<"position: "<<transitions[0]<<" "<<transitions[1]<<" possibility:"<<transitions[2];
                //                qDebug()<<"position: "<<transitions[3]<<" "<<transitions[4]<<" possibility:"<<transitions[5];
                //                qDebug()<<"position: "<<transitions[6]<<" "<<transitions[7]<<" possibility:"<<transitions[8];
                maxValue=maximum(preValueNorth[(int)transitions[0]][(int)transitions[1]],prevValueEast[(int)transitions[0]][(int)transitions[1]]
                        ,prevValueSouth[(int)transitions[0]][(int)transitions[1]],prevValueWest[(int)transitions[0]][(int)transitions[1]]);
                tempValue1=discountFactor*(maxValue*transitions[2]);

                maxValue=maximum(preValueNorth[(int)transitions[3]][(int)transitions[4]],prevValueEast[(int)transitions[3]][(int)transitions[4]]
                        ,prevValueSouth[(int)transitions[3]][(int)transitions[4]],prevValueWest[(int)transitions[3]][(int)transitions[4]]);
                tempValue1+=discountFactor*(maxValue*transitions[5]);

                maxValue=maximum(preValueNorth[(int)transitions[6]][(int)transitions[7]],prevValueEast[(int)transitions[6]][(int)transitions[7]]
                        ,prevValueSouth[(int)transitions[6]][(int)transitions[7]],prevValueWest[(int)transitions[6]][(int)transitions[7]]);
                tempValue1+=discountFactor*(maxValue*transitions[8]);
                valueEast[m][k]=tempValue1+reward[m][k];
                // qDebug()<<"value: "<<valueNorth[m][k];

            }
        }

        //for ActionSouth
        for(int m=0;m<3;m++){
            for(int k=0;k<4;k++){
                if((m==1 && k==1) || (m==0 && k==3) || (m==1 && k==3))
                    continue;
                //                qDebug()<<"position: "<<m<<" "<<k;
                transitions=possibleTransition(m,k,ActionSouth);
                //                qDebug()<<"position: "<<transitions[0]<<" "<<transitions[1]<<" possibility:"<<transitions[2];
                //                qDebug()<<"position: "<<transitions[3]<<" "<<transitions[4]<<" possibility:"<<transitions[5];
                //                qDebug()<<"position: "<<transitions[6]<<" "<<transitions[7]<<" possibility:"<<transitions[8];
                maxValue=maximum(preValueNorth[(int)transitions[0]][(int)transitions[1]],prevValueEast[(int)transitions[0]][(int)transitions[1]]
                        ,prevValueSouth[(int)transitions[0]][(int)transitions[1]],prevValueWest[(int)transitions[0]][(int)transitions[1]]);
                tempValue1=discountFactor*(maxValue*transitions[2]);

                maxValue=maximum(preValueNorth[(int)transitions[3]][(int)transitions[4]],prevValueEast[(int)transitions[3]][(int)transitions[4]]
                        ,prevValueSouth[(int)transitions[3]][(int)transitions[4]],prevValueWest[(int)transitions[3]][(int)transitions[4]]);
                tempValue1+=discountFactor*(maxValue*transitions[5]);

                maxValue=maximum(preValueNorth[(int)transitions[6]][(int)transitions[7]],prevValueEast[(int)transitions[6]][(int)transitions[7]]
                        ,prevValueSouth[(int)transitions[6]][(int)transitions[7]],prevValueWest[(int)transitions[6]][(int)transitions[7]]);
                tempValue1+=discountFactor*(maxValue*transitions[8]);
                valueSouth[m][k]=tempValue1+reward[m][k];
                //qDebug()<<"value: "<<valueNorth[m][k];
            }
        }

        //for ActionWest
        for(int m=0;m<3;m++){
            for(int k=0;k<4;k++){
                if((m==1 && k==1) || (m==0 && k==3) || (m==1 && k==3))
                    continue;
                tempValue1=0;
                // qDebug()<<" ";
                // qDebug()<<"position: "<<m<<" "<<k;
                transitions=possibleTransition(m,k,ActionWest);
                //                qDebug()<<"position: "<<transitions[0]<<" "<<transitions[1]<<" possibility:"<<transitions[2];
                //                qDebug()<<"position: "<<transitions[3]<<" "<<transitions[4]<<" possibility:"<<transitions[5];
                //                qDebug()<<"position: "<<transitions[6]<<" "<<transitions[7]<<" possibility:"<<transitions[8];
                maxValue=maximum(preValueNorth[(int)transitions[0]][(int)transitions[1]],prevValueEast[(int)transitions[0]][(int)transitions[1]]
                        ,prevValueSouth[(int)transitions[0]][(int)transitions[1]],prevValueWest[(int)transitions[0]][(int)transitions[1]]);
                tempValue1=discountFactor*(maxValue*transitions[2]);

                maxValue=maximum(preValueNorth[(int)transitions[3]][(int)transitions[4]],prevValueEast[(int)transitions[3]][(int)transitions[4]]
                        ,prevValueSouth[(int)transitions[3]][(int)transitions[4]],prevValueWest[(int)transitions[3]][(int)transitions[4]]);
                tempValue1+=discountFactor*(maxValue*transitions[5]);

                maxValue=maximum(preValueNorth[(int)transitions[6]][(int)transitions[7]],prevValueEast[(int)transitions[6]][(int)transitions[7]]
                        ,prevValueSouth[(int)transitions[6]][(int)transitions[7]],prevValueWest[(int)transitions[6]][(int)transitions[7]]);
                tempValue1+=discountFactor*(maxValue*transitions[8]);
                valueWest[m][k]=tempValue1+reward[m][k];
                // qDebug()<<"value: "<<valueWest[m][k];
            }
        }

        for(int m=0;m<3;m++)
            for(int k=0;k<4;k++){
                preValueNorth[m][k]=valueNorth[m][k];
                prevValueEast[m][k]=valueEast[m][k];
                prevValueSouth[m][k]=valueSouth[m][k];
                prevValueWest[m][k]=valueWest[m][k];
            }
    }
}

float MDP::maximum(float a, float b , float c , float d){
    return max(max(a,b),max(c,d));
}


double* MDP::possibleTransition(int presentRow, int presentColomn, int action){
    double *possibilities=new double [9];
    switch (action) {
    case ActionNorth:
        if(presentRow>0){
            possibilities[0]=presentRow-1;
            possibilities[1]=presentColomn;
            possibilities[2]=0.8;
        }else if (presentRow==0) {
            possibilities[0]=presentRow;
            possibilities[1]=presentColomn;
            possibilities[2]=0.8;
        }

        if(presentColomn==0){
            possibilities[3]=presentRow;
            possibilities[4]=presentColomn;
            possibilities[5]=0.1;
            possibilities[6]=presentRow;
            possibilities[7]=presentColomn+1;
            possibilities[8]=0.1;
        }else if(presentColomn==3){
            possibilities[3]=presentRow;
            possibilities[4]=presentColomn-1;
            possibilities[5]=0.1;
            possibilities[6]=presentRow;
            possibilities[7]=presentColomn;
            possibilities[8]=0.1;
        }
        else{
            possibilities[3]=presentRow;
            possibilities[4]=presentColomn-1;
            possibilities[5]=0.1;
            possibilities[6]=presentRow;
            possibilities[7]=presentColomn+1;
            possibilities[8]=0.1;
        }
        //obstacle
        if(possibilities[0]==1 && possibilities[1]==1){
            possibilities[0]=presentRow;
            possibilities[1]=presentColomn;
        }

        if(possibilities[3]==1 && possibilities[4]==1){
            possibilities[3]=presentRow;
            possibilities[4]=presentColomn;
        }


        if(possibilities[6]==1 && possibilities[7]==1){
            possibilities[6]=presentRow;
            possibilities[7]=presentColomn;
        }

        return possibilities;
        break;
    case ActionEast:
        if(presentColomn<3){
            possibilities[0]=presentRow;
            possibilities[1]=presentColomn+1;
            possibilities[2]=0.8;
        }else if(presentColomn==3){
            possibilities[0]=presentRow;
            possibilities[1]=presentColomn;
            possibilities[2]=0.8;
        }

        if(presentRow==0){
            possibilities[3]=presentRow;
            possibilities[4]=presentColomn;
            possibilities[5]=0.1;
            possibilities[6]=presentRow+1;
            possibilities[7]=presentColomn;
            possibilities[8]=0.1;
        }else if(presentRow==2){
            possibilities[3]=presentRow-1;
            possibilities[4]=presentColomn;
            possibilities[5]=0.1;
            possibilities[6]=presentRow;
            possibilities[7]=presentColomn;
            possibilities[8]=0.1;
        }else{
            possibilities[3]=presentRow-1;
            possibilities[4]=presentColomn;
            possibilities[5]=0.1;
            possibilities[6]=presentRow+1;
            possibilities[7]=presentColomn;
            possibilities[8]=0.1;
        }
        //obstacle
        if(possibilities[0]==1 && possibilities[1]==1){
            possibilities[0]=presentRow;
            possibilities[1]=presentColomn;
        }

        if(possibilities[3]==1 && possibilities[4]==1){
            possibilities[3]=presentRow;
            possibilities[4]=presentColomn;
        }


        if(possibilities[6]==1 && possibilities[7]==1){
            possibilities[6]=presentRow;
            possibilities[7]=presentColomn;
        }

        return possibilities;

        break;
    case ActionSouth:
        if(presentRow<2){
            possibilities[0]=presentRow+1;
            possibilities[1]=presentColomn;
            possibilities[2]=0.8;
        }else if (presentRow==2) {
            possibilities[0]=presentRow;
            possibilities[1]=presentColomn;
            possibilities[2]=0.8;
        }

        if(presentColomn==0){
            possibilities[3]=presentRow;
            possibilities[4]=presentColomn;
            possibilities[5]=0.1;
            possibilities[6]=presentRow;
            possibilities[7]=presentColomn+1;
            possibilities[8]=0.1;
        }else if(presentColomn==3){
            possibilities[3]=presentRow;
            possibilities[4]=presentColomn-1;
            possibilities[5]=0.1;
            possibilities[6]=presentRow;
            possibilities[7]=presentColomn;
            possibilities[8]=0.1;
        }
        else{
            possibilities[3]=presentRow;
            possibilities[4]=presentColomn-1;
            possibilities[5]=0.1;
            possibilities[6]=presentRow;
            possibilities[7]=presentColomn+1;
            possibilities[8]=0.1;
        }
        //obstacle
        if(possibilities[0]==1 && possibilities[1]==1){
            possibilities[0]=presentRow;
            possibilities[1]=presentColomn;
        }

        if(possibilities[3]==1 && possibilities[4]==1){
            possibilities[3]=presentRow;
            possibilities[4]=presentColomn;
        }


        if(possibilities[6]==1 && possibilities[7]==1){
            possibilities[6]=presentRow;
            possibilities[7]=presentColomn;
        }

        return possibilities;
        break;
    case ActionWest:
        if(presentColomn>0){
            possibilities[0]=presentRow;
            possibilities[1]=presentColomn-1;
            possibilities[2]=0.8;
        }else if(presentColomn==0){
            possibilities[0]=presentRow;
            possibilities[1]=presentColomn;
            possibilities[2]=0.8;
        }

        if(presentRow==0){
            possibilities[3]=presentRow;
            possibilities[4]=presentColomn;
            possibilities[5]=0.1;
            possibilities[6]=presentRow+1;
            possibilities[7]=presentColomn;
            possibilities[8]=0.1;
        }else if(presentRow==2){
            possibilities[3]=presentRow-1;
            possibilities[4]=presentColomn;
            possibilities[5]=0.1;
            possibilities[6]=presentRow;
            possibilities[7]=presentColomn;
            possibilities[8]=0.1;
        }else{
            possibilities[3]=presentRow-1;
            possibilities[4]=presentColomn;
            possibilities[5]=0.1;
            possibilities[6]=presentRow+1;
            possibilities[7]=presentColomn;
            possibilities[8]=0.1;
        }
        //obstacle
        if(possibilities[0]==1 && possibilities[1]==1){
            possibilities[0]=presentRow;
            possibilities[1]=presentColomn;
        }

        if(possibilities[3]==1 && possibilities[4]==1){
            possibilities[3]=presentRow;
            possibilities[4]=presentColomn;
        }


        if(possibilities[6]==1 && possibilities[7]==1){
            possibilities[6]=presentRow;
            possibilities[7]=presentColomn;
        }

        return possibilities;
        break;
    default:
        return possibilities;
        break;
    }
}

