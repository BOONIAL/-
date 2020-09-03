/*
 * @Description: 弗洛伊德算法求最小路径,复杂度n^3，代码更简单,如果是求所有顶点到所有顶点的最短路径可以使用
 * @Author: Ialboon
 * @Date: 2020-09-03 16:33:21
 * @LastEditTime: 2020-09-03 17:34:00
 * @LastEditors: Ialboon
 */
#include<iostream>
#include "AdjacencyMatrix.cpp"
using namespace std;

const int MAXN=100;
//存储最短路径下标的数组
typedef int Pathmatrix[MAXN][MAXN];
//存储到各点最短路径权值和
typedef int ShortPathTable[MAXN][MAXN];

void ShortestPath_Floyd(MGraph G, Pathmatrix *P,ShortPathTable *D){
    int v,w,k;
    //初始化D和P
    for(v=0;v<G.numNodes;v++){
        for(w=0;w<G.numNodes;w++){
            (*D)[v][w]=G.arc[v][w];
            //初始化P
            (*P)[v][w]=w;
        }
    }
    //三重循环更新D和P矩阵
    //以k点为中转，是否能优化
    for(k=0;k<G.numNodes;k++){
        for(v=0;v<G.numNodes;v++){
            for(w=0;w<G.numNodes;w++){
                //如果存在以k为中转的路径比原路径更短，将两点的权值设为更小的一个
                if((*D)[v][w]>(*D)[v][k]+(*D)[k][w]){
                    (*D)[v][w]=(*D)[v][k]+(*D)[k][w];
                    //路径设置经过下标为k的顶点
                    (*P)[v][w]=(*P)[v][k];
                }
            }
        }
    }
}

int main(){
    MGraph *G=new MGraph;
    CreateMGraph(G);
    Pathmatrix *P=new Pathmatrix[G->numNodes];
    ShortPathTable *D=new ShortPathTable[G->numNodes];
    ShortestPath_Floyd(*G,P,D);
    for(int i=0;i<G->numNodes;i++){
        for(int j=0;j<G->numNodes;j++){
            cout<<(*D)[i][j]<<" ";
        }
        cout<<endl;
    }
}