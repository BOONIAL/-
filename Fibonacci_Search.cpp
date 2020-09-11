/*
 * @Description: 斐波那契查找和普通折半查找
 * 原理：最接近查找长度的斐波那契值来确定拆分点;黄金分割。
 * 时间复杂度logn，与折半查找相同
 * @Author: Ialboon
 * @Date: 2020-09-08 22:31:07
 * @LastEditTime: 2020-09-10 10:22:32
 * @LastEditors: Ialboon
 */
#include<iostream>
using namespace std;
const int MAXN=9999;

//斐波那契数列
int F[MAXN];
//生成斐波那契数列
int fibo(int n){
    if(n<=0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fibo(n-1)+fibo(n-2);
}
//key：要查找的值
int Fibonacci_Search(int *a,int n,int key){
    int low,high,mid,i,k;
    //定义最低下标为记录首位
    low=1;
    //定义最高下标为记录末位
    high=n;
    k=0;
    //计算n位于斐波那契数列的位置
    while (n>F[k]-1)
        k++;
    //将不满的数值补完
    for(i=n;i<F[k]-1;i++)
        a[i]=a[n];
    while(low<=high){
        //计算当前分隔的下标
        mid=low+F[k-1]-1;
        if(key<a[mid]){
            //最高下标调到mid-1处
            high=mid-1;
            //斐波那契数列下标减一位
            k=k-1;
        }
        else if(key>a[mid]){
            low=mid+1;
            k=k-2;
        }
        else{
            if(mid<=n)
            //若相等则说明mid即为查找到的位置
                return mid;
            else
            //mid>n则说明是补全数值，返回n
                return n;
        }
    }
    return 0;
}

//key：要查找的值,折半查找
int Binary_Search(int *a,int n,int key){
    int low,high,mid;
    //定义最低下标为记录首位
    low=1;
    //定义最高下标为记录末位
    high=n;
    while(low<=high){
        //位运算
        mid=(low+high)>>2;
        if(key<a[mid])
            //最高下标调到mid-1处
            high=mid-1;
        else if(key>a[mid])
            low=mid+1;
        else{
            return mid;
        }
    }
    return 0;
}