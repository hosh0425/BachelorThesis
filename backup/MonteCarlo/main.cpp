#include <QCoreApplication>
#include <montecarlo.h>
#include <fstream>
#include <math.h>
using namespace std;
int main(int argc, char *argv[])
{
    MonteCarlo montcarlo;
    MonteCarlo::Vertics start,goal;
    int probability[28][28];
    for(int i=0;i<28;i++)
        for(int j=0;j<28;j++)
            probability[i][j]=0;

    srand(time(0));
    for(int i=0;i<500;i++){
        montcarlo.randNum[i]=(((double) rand() / (RAND_MAX)))-0.5;
        // qDebug()<<montcarlo.randNum[i];
    }
    int tempProbability;
    for(int i=0;i<28;i++){
        for(int j=0;j<28;j++){
            if(montcarlo.edges[i][j]==1){
                if(i<=j){
                    start.x=montcarlo.points[i][0];
                    start.y=montcarlo.points[i][1];
                    start.theta=montcarlo.points[i][2];
                    goal.x=montcarlo.points[j][0];
                    goal.y=montcarlo.points[j][1];
                    goal.theta=montcarlo.points[j][2];
                    probability[i][j]=montcarlo.DFL_tracker(start,goal);
                }else{
                    start.x=montcarlo.points[i][0];
                    start.y=montcarlo.points[i][1];
                    start.theta=montcarlo.points[i][2];
                    goal.x=montcarlo.points[j][0];
                    goal.y=montcarlo.points[j][1];
                    goal.theta=montcarlo.points[j][2];
                    tempProbability=montcarlo.DFL_tracker(start,goal);
                    probability[i][j]=min(probability[j][i],tempProbability);
                    probability[j][i]=min(probability[j][i],tempProbability);

                }

            }
        }
    }
    ofstream outdata;
    outdata.open("/home/hossein/Desktop/probability.txt");

    for(int i=0;i<28;i++){
        outdata<<"\n";
        outdata<<"{";
        for(int j=0;j<28;j++){
            outdata<<probability[i][j]<<",";
        }
        outdata<<"},";
    }
    outdata.close();


    return 0;
}
