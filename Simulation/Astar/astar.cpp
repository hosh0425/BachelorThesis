#include "astar.h"

Astar::Astar()
{
    for(int i=0;i<nodeNumber;i++){
        fScore[i]=INFINITY;
        gScore[i]=INFINITY;
        closeSet[i]=openSet[i]=0;
    }
    gScore[startNode]=0;
    hurestic[startNode]=sqrt(pow(points[startNode][0]-points[goalNode][0],2)+pow(points[startNode][1]-points[goalNode][1],2));
    fScore[startNode]=hurestic[startNode];
    openSet[startNode]=1; //start node in openSet

    for(int i=0;i<28;i++)
        for(int j=0;j<28;j++)
            weight[i][j]=distances[i][j];
}

/*
 *  int OptimalPath[nodeNumber];
    int counter=0;
    int parent=goalNode;
    for(int i=pathcounter;i>-1;i--){
       // for(int k=i;k>-1;k--){
            for(int j=0;j<4;j++)
                if(edges[parent][j]==path[i]){
                    qDebug()<<parent<<" is parent of node "<<path[i];
                    OptimalPath[counter++]=parent;
                    parent=path[i];
                    break;
                }

        //}
    }
    */
void Astar::findPath(){
    int OptimalPath[nodeNumber];
    int counter=0;
    int parent=goalNode;

    while (true) {
        if(parent==startNode)
            break;
        OptimalPath[counter++]=parent;
        parent=path[parent];
    }


    qDebug()<<"Optimal Path";
    for(int i=0;i<counter;i++){
        qDebug()<<OptimalPath[i];
    }
    qDebug()<<startNode;
}

void Astar::aStar(){
    while(true){
        /*
         *  a) find the node with the least f on
         *   the open list, call it "q"
         */

        float maxVal=INFINITY;
        //        qDebug()<<"fscores:";
        //        for(int i=0;i<nodeNumber;i++)
        //            qDebug()<<fScore[i];
        for(int i=0;i<nodeNumber;i++){
            if(fScore[i]<maxVal && openSet[i]==1){
                q=i;
                maxVal=fScore[i];
            }
        }

        qDebug()<<"processing node number: "<<q;


        if(q==goalNode){
            //path[pathcounter++]=goalNode;
            qDebug()<<"goal node detected"<<"this is path:";
            for(int k=0;k<nodeNumber;k++)
                qDebug()<<k<<" "<<path[k]<<" ";
            findPath();
            exit(0);
        }

        /*
         * b) pop q off the open list
         */
        openSet[q]=0;

        /*
         * c) add q to the close list
         */
        closeSet[q]=1;


        /*
         * d) for each adjacent of q
         */

        //har node be 4 ta vasle hamishe
        for(int j=0;j<nodeNumber;j++){
            // usleep(100000);
            if(edges[q][j]==1){
                qDebug()<<"node "<<q<<"is connected to node "<<j;

                if(closeSet[j]==1)
                    continue;

                float cost=gScore[q]+weight[q][j];


                if(openSet[j]==0)
                    openSet[j]=1;
                else if(cost>=gScore[j])
                    continue;

                gScore[j]=cost;
                hurestic[j]=sqrt(pow(points[j][0]-points[goalNode][0],2)+pow(points[j][1]-points[goalNode][1],2));
                fScore[j]=gScore[j]+hurestic[j];
                path[j]=q;

            }

        }

    }
}
