#include "mainwindow.h"
#include <QPainter>
#include <QApplication>
#include <QLabel>
#include <stdlib.h>
#include <QDebug>
#include <unistd.h>
#include <time.h>
#include <fstream>
using std::ofstream;

//using namespace std;
float distance[28][2];
int pointsSize;
void sort(){
    float temp;
    for(int i=0;i<pointsSize;i++){
        for(int j=i;j<pointsSize;j++){
            if(distance[i][0]>distance[j][0]){
                temp=distance[i][0];
                distance[i][0]=distance[j][0];
                distance[j][0]=temp;

                temp=distance[i][1];
                distance[i][1]=distance[j][1];
                distance[j][1]=(int)temp;
            }
        }
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //ofstream outdata;
    //outdata.open("/home/hossein/Desktop/graph.txt");

    //    float points[28][2]={{2.6,3},{2.8,1.2},{1.7,1.9},{1,2.9},{0.4,1.2},{1.3,0.8},{2.9,0},{1.7,-0.7},{2.7,-2},{2.8,-4},{2.2,-3.2},{0.7,-0.8}
    //                          ,{1,-2.2},{0,-3.2},{-0.7,-1.8},{0,0},{1.5,-4},{-1.5,-2},{-1.2,-0.8},
    //                          {-0.8,0.8},{-0.6,1.5},{-1.2,3},{-2,2.7},{-1.5,1.2},{-1.9,0.1},{-2,-4},{-0.5,2.5},{-1,3}};
    float points[28][3]={{2.6,3,1.2},{2.8,1.2,0.7},{1.7,1.9,1.7},{1,2.9,-2},{0.4,1.2,0.3},//badi 5
                         {1.3,0.8,-0.9},{2.9,0,1},{1.7,-0.7,-2},{2.7,-2,-0.5},{2.8,-4,0.6} //badi10
                         ,{2.2,-3.2,2.5},{0.7,-0.8,0.5},{1,-2.2,-0.3},{0,-3.2,-3},{-0.7,-1.8,2.9},//badi15
                         {0,0,-0.7},{1.5,-4,1.7},{-1.5,-2,-0.9},{-1.2,-0.8,-2.2},{-0.8,0.8,0.8},//badi20
                         {-0.6,1.5,2.5},{-1.2,3,1},{-2,2.7,1.9},{-1.5,1.2,-2},{-1.9,0.1,-3},//badi25
                         {-1.5,-3.5,3},{-0.5,2.5,0.2},{-1,3,0.9}};
    pointsSize=28;
    float weight[pointsSize][pointsSize];
    for(int i=0;i<pointsSize;i++)
        for(int j=0;j<pointsSize;j++)
            weight[i][j]=-1;

    int edges[pointsSize][pointsSize];
    for(int i=0;i<pointsSize;i++)
        for(int j=0;j<pointsSize;j++)
            edges[i][j]=-1;
    for(int i=0;i<pointsSize;i++)
        for(int j=0;j<2;j++)
            distance[i][j]=1000;


    for(int i=0;i<pointsSize;i++){
        points[i][0]=points[i][0]*100+214;
        points[i][1]=points[i][1]*100+430;
    }
    distance[0][0]=1;
    distance[0][1]=1;
    QPixmap pm(520,780);
    pm.fill();
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing, true);
    QPen penMain(Qt::blue, 2);
    QPen penRandom(Qt::green, 2);
    QPen penLine(Qt::red, 1);
    p.setPen(penRandom);
   // p.setBrush(QBrush(Qt::red));

    float obstacles[6][3]={{-1.14,-3.3,0.65},{-0.28,-2.84,0.8},{0.01,-2,0.8},{-0.14,1.8,0.8},{1.96,1.7,0.7},{-1.76,1.9,0.35}};
//    p.drawEllipse(100,100, 65, 65);
//    p.drawEllipse(186,146, 80, 80);
//    p.drawEllipse(215,230, 80, 80);
//    p.drawEllipse(200,610, 80, 80);
    //p.drawEllipse(38,620, 35, 35);
    for(int i=0;i<6;i++)
        p.drawEllipse(obstacles[i][0]*100+214,obstacles[i][1]*100+430,obstacles[i][2]*100,obstacles[i][2]*100);

    for(int i=0;i<6;i++)
        p.drawEllipse(obstacles[i][0]*100+214+obstacles[i][2]*100/2,obstacles[i][1]*100+430+obstacles[i][2]*100/2,2,2);



    //p.rotate(-45);
    QRect rect(50,50,300,300);
    //    p.drawRect(rect);
    // p.rotate(+45);

    p.setBrush(QBrush(Qt::black));
    p.setPen(penMain);





    QLabel l;
    QColor color;



    for(int m=0;m<pointsSize;m++){
        for(int i=0;i<pointsSize;i++){
            if(i!=m){
                distance[i][0]=sqrt(pow(points[m][0]-points[i][0],2.0)+pow(points[m][1]-points[i][1],2.0));
                distance[i][1]=i;
            }
        }
        distance[m][0]=1000;
        distance[m][1]=m;
        sort();
        //        if(distance[0][0]<30) //noghteye jadid dar 80 santie ye noghte bood velesh kn
        //            break;
        p.setPen(penLine);
        color.setRgb(qrand()%255,qrand()%255,qrand()%255);

        for(int i=0;i<pointsSize;i++){ //4 near neighbor
            //if(distance[i][0]>100 && distance[i][0]<300){
            penMain.setColor(color);
            penMain.setWidth(2);
            p.setPen(penMain);
            qDebug()<<distance[m][i];

            if(distance[i][0]<200){
                edges[m][(int)distance[i][1]]=1;
                weight[m][(int)distance[i][1]]=distance[i][0];
                p.drawLine(QPointF(points[m][0],points[m][1]),QPointF(points[(int)distance[i][1]][0],points[(int)distance[i][1]][1]));
            }else{
                edges[m][(int)distance[i][1]]=0;
                weight[m][(int)distance[i][1]]=0;
            }
        }
    }

    for(int i=0;i<pointsSize;i++){
        rect.setRect(points[i][0]+10,points[i][1]+10,20,20);
        p.drawText(rect,QString::number(i));
        p.drawEllipse(points[i][0]-10,points[i][1]-10, 15, 15);
    }

//    for(int i=0;i<pointsSize;i++){
//        outdata<<"\n";
//        for(int j=0;j<pointsSize;j++)
//            outdata<<edges[i][j]<<",";
//    }
//    outdata<<"\n";
//    for(int i=0;i<pointsSize;i++){
//        outdata<<"\n";
//        for(int j=0;j<pointsSize;j++)
//            outdata<<weight[i][j]<<",";
//    }
//    outdata.close();

    l.setPixmap(pm);
    l.show();

    return a.exec();
}




