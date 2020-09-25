/*
 * @Description: 归并排序 O(nlogn)
 * @Author: Ialboon
 * @Date: 2020-09-24 22:29:06
 * @LastEditTime: 2020-09-25 10:07:39
 * @LastEditors: Ialboon
 */
#include<iostream>
#include "SqList.cpp"
using namespace std;

const int MAXSIZE=999;
//将有序的SR[i..m]和SR[m+1,n]归并为有序的TR[i..n]
void Merge(int *SR,int *TR,int i,int m,int n){
    int j,k,l;
    for(j=m+1,k=i;i<=m&&j<=n;k++){
        if(SR[i]<SR[j])
            TR[k]=SR[i++];
        else
            TR[k]=SR[j++];
    }
    //左右两边可能会剩下一边，但不会有两边
    //将剩余的SR[i..m]复制到TR
    if(i<=m){
        for(l=0;l<=m-i;l++)
            TR[k+l]=SR[i+l];
    }
    //将剩余的SR[m+1..n]复制到TR
    if(j<=n){
        for(l=0;l<=n-j;l++)
            TR[k+l]=SR[j+l];
    }
}

//将SR[s..t]归并排序为TR1[s..t]
void MSort(int *SR,int *TR1,int s,int t){
    int m;
    int TR2[MAXSIZE+1];
    if(s==t)
        TR1[s]=SR[s];
    else{
        m=(s+t)/2;//将SR[s..t]平分为SR[s..m]和SR[m+1..t]
        MSort(SR,TR2,s,m);
        MSort(SR,TR2,m+1,t);
        Merge(TR2,TR1,s,m,t);//将有序的TR2[s..m]和TR2[m+1,t]归并为有序的TR1[s..t]
    }
}

//非递归归并排序（空间复杂度降低）

//将SR[]中相邻长度为s的子序列两两归并到TR[]
void MergePass(int SR[],int TR[],int s,int n){
    int i=1;
    int j;
    while (i<=n-2*s+1){
        Merge(SR,TR,i,i+s-1,i+2*s-1);//两两归并
        i=i+2*s;
    }
    if(i<n-s+1)
        Merge(SR,TR,i,i+s-1,n);
    else
        for(j=i;j<=n;j++)
            TR[j]=SR[j];
}

//对顺序表L作归并非递归排序
template<class T>
void MergeSort2(SqList<T> *L){
    int *TR=new T [L->length+1];
    int k=1;
    while(k<L->length){
        MergePass(L->r,TR,k,L->length);
        k=2*k;//子序列长度加倍
        MergePass(TR,L->r,k,L->length);
        k=2*k;
    }
}

int main(){
    SqList<int> *sq;
    sq->length=9;
    sq->r=new int [10]{0,9,1,5,8,3,7,4,6,2};
    MergeSort2(sq);
    for(int i=1;i<=sq->length;i++){
        cout<<sq->r[i]<<" ";
    }
}