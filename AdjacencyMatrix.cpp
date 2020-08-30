/*
 * @Description: 邻接矩阵
 * @Author: Ialboon
 * @Date: 2020-08-28 21:17:06
 * @LastEditTime: 2020-08-29 11:58:15
 * @LastEditors: Ialboon
 */
#include<iostream>
using namespace std;

const int INFINITY=0x3f3f3f3f;
class MGraph{
public:
    int numNodes,numEdges;
    //顶点表
    int *vexs;
    //保存点与点的关系
    int **arc;
    void init(){
        vexs=new int[numNodes];
        arc=new int *[numNodes];
        for(int j=0;j<numNodes;j++)
            arc[j]=new int [numNodes];
    }
};

void CreateMGraph(MGraph *G){
    int i,j,k,w;
    cin>>G->numNodes>>G->numEdges;
    G->init();
    for(i=0;i<G->numNodes;i++)
        cin>>G->vexs[i];
    for(i=0;i<G->numNodes;i++)
        for(j=0;j<G->numNodes;j++)
            G->arc[i][j]=INFINITY;
    for(k=0;k<G->numEdges;k++){
        cin>>i>>j>>w;
        G->arc[i][j]=w;
        G->arc[j][i]=w;
    }
}