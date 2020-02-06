#include <mdp.h>

int main(int argc, char *argv[])
{
    MDP mdp;
    mdp.optimalValueFunction();

    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++){
            qDebug()<<" ";
            qDebug()<<"north "<<i<<" "<<j<<" "<<mdp.valueNorth[i][j];
            qDebug()<<"east  "<<i<<" "<<j<<" "<<mdp.valueEast[i][j];
            qDebug()<<"south "<<i<<" "<<j<<" "<<mdp.valueSouth[i][j];
            qDebug()<<"west  "<<i<<" "<<j<<" "<<mdp.valueWest[i][j];

        }


    return 0;
}
