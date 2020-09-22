/*
 * @Description: Shell排序 O(n^(3/2))
 * @Author: Ialboon
 * @Date: 2020-09-22 20:59:15
 * @LastEditTime: 2020-09-22 22:15:54
 * @LastEditors: Ialboon
 */
#include<iostream>
#include"SqList.cpp"
using namespace std;

template<class T>
void ShellSort(SqList<T> *L){
    int i,j;
    int increment=L->length;
    do{
        increment=increment/3+1;//增量序列
        for(i=increment+1;i<=L->length;i++){
            if(L->r[i]<L->r[i-increment]){
                //需将L->r[i]插入到有序增量子表
                L->r[0]=L->r[i];//暂存
                for(j=i-increment;j>0&&L->r[0]<L->r[j];j-=increment)
                    L->r[j+increment]=L->r[j];//记录后移，寻找插入位置。j递减，以increment为单位。
                L->r[j+increment]=L->r[0];//插入
            }
        }
    } while (increment>1);
}

int main(){
    SqList<int> *sq;
    sq->length=9;
    sq->r=new int [10]{0,9,1,5,8,3,7,4,6,2};
    ShellSort(sq);
    for(int i=1;i<=sq->length;i++){
        cout<<sq->r[i]<<" ";
    }
}