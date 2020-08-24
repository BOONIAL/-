/*
 * @Description: 根据递归规律由中序和后序序列推前序序列
 * @Author: Ialboon
 * @Date: 2020-08-22 11:51:32
 * @LastEditTime: 2020-08-22 12:36:05
 * @LastEditors: Ialboon
 */
#include<iostream>
using namespace std;

void Print(string a,string b){
    //a:中序 b:后序
    if(a.length()>0){
        //用中或后都可以
        //cout<<a<<" "<<b<<endl;
        int aLen=a.length();
        int bLen=b.length();

        //打出后序的最后一位
        int fin=bLen-1;
        cout<<b[fin]<<" ";

        //递归部分,根据中序划分
        int k=a.find(b[fin]);
        cout<<k<<" "<<bLen-1-k<<endl;
        Print(a.substr(0,k),b.substr(0,k));
        Print(a.substr(k+1),b.substr(k,bLen-1-k));
    }
}

int main(){
    string a={"ABCDEFG"};
    string b={"BDCAFGE"};
    Print(a,b);
}