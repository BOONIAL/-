/*
 * @Description: 二叉排序树
 * @Author: Ialboon
 * @Date: 2020-09-12 17:01:28
 * @LastEditTime: 2020-09-12 21:45:25
 * @LastEditors: Ialboon
 */
#include<iostream>
#include "BinaryTree.cpp"
using namespace std;

//递归查找二叉树BT是否存在key
//指针f指向BT的双亲，其初始值为NULL
//若查找成功，则指针p指向该数据元素节点，并返回TRUE
//否则p指向查找路径上访问的最后一个节点并返回FALSE
template<class T>
bool SearchBST(BitNode<T> *(&BT),int key,BitNode<T> *(&f),BitNode<T> *(&p)){
    if(!BT){
        p=f;
        return false;
    }
    else if(key==BT->data){
        p=BT;
        return true;
    }
    //如果key小于该节点，则向左移动
    else if(key<BT->data)
        return SearchBST(BT->lchild,key,BT,p);
    else
        return SearchBST(BT->rchild,key,BT,p);
}

//当二叉排序树T中不存在关键字key的数据元素时
//插入key并返回TRUE，否则返回false
template<class T>
bool InsertBST(BitNode<T> *(&BT),int key){
    BitNode<T> *p,*s,*t;
    t=NULL;
    //如果查找不成功,则插入
    if(!SearchBST(BT,key,t,p)){
        s=new BitNode<T>;
        s->data=key;
        s->lchild=s->rchild=NULL;
        if(!p)
            BT=s;
        else if(key<p->data)
            p->lchild=s;
        else
            p->rchild=s;
        return true;
    }
    else
        return false;
}

//删除某节点
template<class T>
bool DeleteBST(BitNode<T> *BT,int key){
    if(!BT)
        return false;
    else{
        if(key==BT->data)
            return delNode(BT);
        else if(key<BT->data)
            return DeleteBST(BT->lchild,key);
        else
            return DeleteBST(BT->rchild,key);
    }

}
//从二叉排序树中删除节点p，并重接左或右子树
template<class T>
bool delNode(BitNode<T> *p){
    BitNode<T> *q,*s;
    //只有左或右子树或者只是叶子
    if(p->rchild==NULL){
        q=p;
        p=p->lchild;
        delete q;
    }
    else if(p->lchild==NULL){
        q=p;
        p=p->rchild;
        delete q;
    }
    //左右子树均不空
    else{
        q=p;
        s=p->lchild;
        //找到左子树的最右端
        while(s->rchild){
            q=s;
            s=s->rchild;
        }
        //赋值
        p->data=s->data;
        //如果q!=p把左子树最右端的节点的左孩子接给q
        if(q!=p)
            q->rchild=s->lchild;
        else
            q->lchild=s->lchild;
        delete s;
    }
    return true;
}

int main(){
    int i;
    int a[10]={62,88,58,47,35,73,51,99,37,93};
    BitNode<int> *BT=NULL;
    for(i=0;i<10;i++){
        InsertBST(BT,a[i]);
    }
    DeleteBST(BT,47);
    cout<<BT->lchild->lchild->data;
    
}