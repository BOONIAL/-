/*
 * @Description: KMP模式匹配算法。介绍：https://blog.csdn.net/v_july_v/article/details/7041827
 * @Author: Ialboon
 * @Date: 2020-08-18 19:53:03
 * @LastEditTime: 2020-08-19 21:58:35
 * @LastEditors: Ialboon
 */
#include<iostream>
using namespace std;

void GetNext(string p,int *next){
    //next的值
    int k=-1;
    int j=0;
    next[0]=-1;
    while(j<p.length()){
        //p[k]：前缀 p[j]：后缀
        if(k==-1||p[k]==p[j]){
            //printf("%d: p[%c] %d: p[%c]\n",k,p[k],j,p[j]);
            //继续向后比较
            j++;
            k++;
            //记录j前字符串的前后缀相似度，在j位置记录
            next[j]=k;
            //printf("next[%d]=%d\n\n",j,k);
        }
        else{
            //printf("else:k=next[%d]=%d\n",k,next[k]);
            //寻找长度更短的相同前后缀,从前缀末端开始递归搜索
            k=next[k];
        }
    }
}

//函数GetNext的优化：不能允许p[j] = p[next[j]]导致的低效
void GetNextval(string p,int *next){
    int k=-1;
    int j=0;
    next[0]=-1;
    while(j<p.length()){
        if(k==-1||p[k]==p[j]){
            j++;
            k++;
            //修改的部分
            //k=-1的情况
            if(p[j]!=p[k])
                next[j]=k;
            //继续递归
            else
                next[j]=next[k];
            
        }
        else{
            k=next[k];
        }
    }
}
int kMPSearch(string s,string p){
    //s:主串 p:模式串
    int i=0;
    int j=0;
    int sLen=s.length();
    int pLen=p.length();
    int next[pLen];
    GetNext(p,next);
    while(i<sLen && j<pLen){
        if(j==-1||s[i]==p[j]){
            //printf("%d: s[%c] %d: p[%c]\n",i,s[i],j,p[j]);
            i++;
            j++;
        }
        else{
            //printf("else:j=next[%d]=%d\n\n",j,next[j]);
            //递归，j往前回溯到前缀重合部分，相当于模式串右移j-next[j]位，与后缀部分重合（如果有）。
            j=next[j];
        }
    }
    //返回匹配的位置，没有则返回-1
    if(j==pLen)
        return i-j;
    else
        return -1;
}

int main(){
    string S={"BBC ABCDAB ABCDABCDABDE"};
    string T={"ABCDABD"};
    int next[255];
    cout<<kMPSearch(S,T);
}