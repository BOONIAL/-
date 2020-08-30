/*
 * @Description: Prim算法找最小生成树
 * @Author: Ialboon
 * @Date: 2020-08-28 21:36:35
 * @LastEditTime: 2020-08-29 11:21:34
 * @LastEditors: Ialboon
 */
#include<iostream>
#include"AdjacencyMatrix.cpp"
using namespace std;

void MiniSpanTree_Prim(MGraph *G){
    int min,i,j,k,len;
    len=G->numNodes;
    //保存相关顶点下标
    int adjvex[len];
    int lowcost[len];
    //从v0开始加入生成树
    lowcost[0]=0;
    //初始化第一个顶点下标为0
    adjvex[0]=0;
    //循环除下标为0外的全部顶点
    for(i=1;i<G->numNodes;i++){
        lowcost[i]=G->arc[0][i];
        adjvex[i]=0;
    }
    for(i=1;i<G->numNodes;i++){
        min=INFINITY;
        j=1,k=0;
        //循环全部顶点
        while(j<G->numNodes){
            //如果权值不为0且小于min
            if(lowcost[j]!=0&&lowcost[j]<min){
                min=lowcost[j];
                k=j;
            }
            j++;
        }
        cout<<"("<<adjvex[k]<<","<<k<<")"<<endl;
        //顶点完成任务，标记为0，纳入生成树
        lowcost[k]=0;
        //以该点为出发点，找到短边并取代lowcost对应数值在循环中不断更新该数组
        for(j=1;j<G->numNodes;j++){
            if(lowcost[j]!=0 && G->arc[k][j]<lowcost[j]){
                //较小权值存入lowcost
                lowcost[j]=G->arc[k][j];
                //下标为k的顶点存入adjvex
                adjvex[j]=k;
            }
        }
    }
}

int main(){
    MGraph *G=new MGraph;
    CreateMGraph(G);
    MiniSpanTree_Prim(G);
}