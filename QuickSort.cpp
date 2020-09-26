/*
 * @Description: 快速排序
 * @Author: Ialboon
 * @Date: 2020-09-26 09:05:49
 * @LastEditTime: 2020-09-26 10:20:40
 * @LastEditors: Ialboon
 */

#include<iostream>
#include "SqList.cpp"
using namespace std;

//交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置
//此时在它之前（后）的记录均不大（小）于它
template<class T>
int Partition(SqList<T> *L,int low,int high){
    int pivotkey;
    
    //三数取中优化
    int m=low+(high-low)/2;
    if(L->r[low]>L->r[high])
        swap(L,low,high);//保证左端小
    if(L->r[m]>L->r[high])
        swap(L,high,m);//保证中间小
    if(L->r[m]>L->r[low])
        swap(L,m,low);
    //此时L->r[low]为上面三个数中的中间值

    //对枢轴值减少不必要的交换
    pivotkey=L->r[low];//用子表的第一个记录作枢轴记录
    L->r[0]=pivotkey;//备份到L->r[0]
    //从表的两端交替向中间扫描
    while(low<high){
        while(low<high&&L->r[high]>=pivotkey)
            high--;
        L->r[low]=L->r[high];
        //swap(L,low,high);//比记录小的交换到低端
        while(low<high&&L->r[low]<=pivotkey)
            low++;
        L->r[high]=L->r[low];
        //swap(L,low,high);//比记录大的交换到高端
    }
    L->r[low]=L->r[0];//将枢轴值替换回L->r[low]
    return low;
}

template<class T>
void QSort(SqList<T> *L,int low,int high){
    int pivot;
    if(low<high){
        pivot=Partition(L,low,high);//将L->r[low..high]一分为二，算出枢轴值pivot
        QSort(L,low,pivot-1);//低子表递归排序
        QSort(L,pivot+1,high);
    }
}

int main(){
    SqList<int> *sq;
    sq->length=9;
    sq->r=new int [10]{0,9,1,5,8,3,7,4,6,2};
    QSort(sq,1,9);
    for(int i=1;i<=sq->length;i++){
        cout<<sq->r[i]<<" ";
    }
}