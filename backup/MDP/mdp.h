#ifndef MDP_H
#define MDP_H

#include <cstdlib>
#include <QDebug>
#include <math.h>
#define ActionNorth 1
#define ActionEast 2
#define ActionSouth 3
#define ActionWest 4

using namespace std;

class MDP
{
public:
    MDP();
    double discountFactor=0.99;
    double reward[3][4]={{-0.02,-0.02,-0.02,1},{-0.02,-0.2,-0.02,-1},{-0.02,-0.02,-0.02,-0.02}};
    double valueNorth[3][4], valueEast[3][4],valueSouth[3][4],valueWest[3][4];
    double preValueNorth[3][4], prevValueEast[3][4],prevValueSouth[3][4],prevValueWest[3][4];

    double* possibleTransition(int presentRow,int presentColomn, int action);
    void optimalValueFunction();
    float maximum(float a, float b , float c , float d);
};

#endif // MDP_H
