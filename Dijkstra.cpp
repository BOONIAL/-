/*
 * @Description: 迪杰斯特拉算法寻找最短路径，O(n^2)
 * @Author: Ialboon
 * @Date: 2020-09-03 10:46:07
 * @LastEditTime: 2020-09-03 15:54:11
 * @LastEditors: Ialboon
 */
#include<iostream>
#include "AdjacencyMatrix.cpp"
using namespace std;

const int MAXN=100;
//存储最短路径下标的数组
typedef int Pathmatrix[MAXN];
//存储到各点最短路径权值和
typedef int ShortPathTable[MAXN];

//P[v]的值为前驱顶点下标，D[v]表示v0到v的最短路径长度和
void ShortestPath_Dijkstra(MGraph G,int v0, Pathmatrix *P, ShortPathTable *D){
    int v,w,k,min;
    //final[w]=1表示顶点v0至vw的最短路径完成
    int final[MAXN];
    //初始化数据
    for(v=0;v<G.numNodes;v++){
        final[v]=0;
        (*D)[v]=G.arc[v0][v];
        (*P)[v]=0;
    }
    //v0至v0路径为0
    (*D)[v0]=0;
    //v0至v0不需要求路径
    final[v0]=1;
    //开始循环，每次求得v0到某个顶点v的最短路径
    for(v=1;v<G.numNodes;v++){
        min=INFINITY;
        //寻找离v0最近的顶点
        for(w=0;w<G.numNodes;w++){
            if(!final[w]&&(*D)[w]<min){
                k=w;
                //w顶点离v0更近
                min=(*D)[w];
            }
        }
        //目前找到的最近顶点置为1
        final[k]=1;
        for(w=0;w<G.numNodes;w++){
            //如果经过v顶点的路径比现在的路径短的话
            if(!final[w]&&min+G.arc[k][w]<(*D)[w]){
                //说明找到了更短的路径，修改D[w]和P[w]
                (*D)[w]=min+G.arc[k][w];
                //前置顶点
                (*P)[w]=k;
            }
        }
    }
}

int main(){
    MGraph *G=new MGraph;
    CreateMGraph(G);
    Pathmatrix *P=new Pathmatrix[G->numNodes];
    ShortPathTable *D=new ShortPathTable[G->numNodes];
    ShortestPath_Dijkstra(*G,0,P,D);
    for(int i=0;i<G->numNodes;i++){
        cout<<(*P)[i]<<" ";
    }
}
 
