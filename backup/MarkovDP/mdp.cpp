#include "mdp.h"
#include <qdebug.h>
MDP::MDP()
{
    for(int i=0;i<nodeNumber;i++)
        for(int j=0;j<nodeNumber;j++){
            value[i][j]=preValue[i][j]=0;
            weight[i][j]=distances[i][j];
            reward[i][j]=0.02;

        }



    for(int i=0;i<nodeNumber;i++)
        for(int j=0;j<nodeNumber;j++){
            if(edges[i][j]==1 && i==goalNode){        //oon node hayi ke be goalNode vaslan value baraye oona 1000
                value[i][j]=preValue[i][j]=-1;
            }
        }

}

double minValues[nodeNumber];
void MDP::optimalValueFunction(){

    ofstream outdata;

    outdata.open("/home/hossein/Desktop/MDPvalue.txt");
    for(int i=0;i<iterateValue;i++){

        for(int y=0;y<nodeNumber;y++)
            for(int z=0;z<nodeNumber;z++){
                preValue[y][z]=value[y][z];
                minValues[z]=1000000000;
            }

        for(int m=0;m<nodeNumber;m++){
            for(int k=0;k<nodeNumber;k++){
                if(m!=goalNode){
                    if(edges[m][k]==1){

                        for(int z=0;z<nodeNumber;z++)
                            minValues[z]=1000000000;
                        for(int z=0;z<nodeNumber;z++)
                            if(edges[k][z]==1){
                                minValues[z]=preValue[k][z];
                                //qDebug()<<minValues[z];
                            }


                        //qDebug()<<"for "<<m<<" "<<k<<" minimum()"<<minimum()<<"fault "<<(101-probability[m][k])/100<<"dis weight "<<discountFactor*(weight[m][k]/10);

                        value[m][k]=discountFactor*(minimum()*(probability[m][k]))/100;
                        value[m][k]+=0.02;//weight[m][k]/1000; //0.02


                    }
                }
            }
        }
    }


    findPath();
    for(int y=0;y<nodeNumber;y++){
        outdata<<"\n";
        for(int z=0;z<nodeNumber;z++)
            outdata<<value[y][z]<<" ";
    }

}

void MDP::findPath(){
    int tempStart=startNode;
    while(true){
        qDebug()<<tempStart;
        for(int i=0;i<nodeNumber;i++)
            minValues[i]=value[tempStart][i];
        tempStart=minimumPath();
        if(tempStart==goalNode){
            qDebug()<<tempStart;
            break;
        }
    }
}

int MDP::minimumPath(){
    double min=100000;
    int minIndex;
    for(int i=0;i<nodeNumber;i++)
        if(minValues[i]<min){
            min=minValues[i];
            minIndex=i;
        }

    return minIndex;

}

double MDP::minimum(){
    double min=100000;
    for(int i=0;i<nodeNumber;i++)
        if(minValues[i]<min)
            min=minValues[i];

    return min;

}

