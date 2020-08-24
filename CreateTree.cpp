/*
 * @Description: 二叉树建立
 * @Author: Ialboon
 * @Date: 2020-08-22 20:47:58
 * @LastEditTime: 2020-08-23 21:37:04
 * @LastEditors: Ialboon
 */
#include<iostream>
using namespace std;

template <class T>
class BitNode{
public:
    T data;
    BitNode *lchild;
    BitNode *rchild;
    BitNode(T ddata):data(ddata),lchild(NULL),rchild(NULL){};
    BitNode():data(0),lchild(NULL),rchild(NULL){};
};

//“#”表示虚节点,按前序序列创建二叉树
template <class T>
void CreateBiTree(BitNode<T> *t){
    T dt;
    cin>>dt;
    if(ch=='#')
        *t=NULL;
    else
    {
        //赋值
        t=new BitNode(dt);
        //递归构建
        CreateBiTree(t->lchild);
        CreateBiTree(t->rchild);
    }
    
}

