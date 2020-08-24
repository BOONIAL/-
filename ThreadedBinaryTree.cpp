/*
 * @Description: 二叉树的线索化和遍历，以中序序列为例子
 * @Author: Ialboon
 * @Date: 2020-08-22 21:39:37
 * @LastEditTime: 2020-08-24 16:14:05
 * @LastEditors: Ialboon
 */
#include<iostream>
using namespace std;

//线索二叉树节点
template <class T>
class BitNode{
public:
    T data;
    BitNode *lchild;
    BitNode *rchild;
    
    //tag标记：0表示指向孩子，1表示指向前后驱的线索
    int LTag;
    int RTag;

    BitNode<T>(T ddata):data(ddata),lchild(NULL),rchild(NULL),LTag(0),RTag(0){
        //cout<<"called"<<endl;
    };
    BitNode<T>():data(0),lchild(NULL),rchild(NULL),LTag(0),RTag(0){
        //cout<<"called"<<endl;
    };
};

//“#”表示虚节点,按前序序列创建二叉树
template <class T>
//参数使用引用,否则会导致内存区域没有改变
void CreateBiTree(BitNode<T> *(&t)){
    T dt;
    cin>>dt;
    if(dt=='#')
        t=NULL;
    else
    {
        //赋值
        t=new BitNode<T>(dt);
        //cout<<t->data<<endl;
        //递归构建
        CreateBiTree(t->lchild);
        CreateBiTree(t->rchild);
    }
    
}

BitNode<char> *pre=new BitNode<char>(0);//实例化全局变量,由于重载函数没有定义指针型，所以不用

//中序遍历进行线索化
template <class T>
void InThreading(BitNode<T> *(&p)){
    if(p){
        //递归
        InThreading(p->lchild);
        //cout<<p->data<<pre.data<<endl;
        //如果没有左孩子
        if(!p->lchild){
            p->LTag=1;
            //cout<<"ltag:"<<p->data<<" "<<p->LTag<<endl;
            //左孩子指针指向前驱
            p->lchild=pre;
        }
        
        //前驱没有右孩子
        if(!pre->rchild){
            pre->RTag=1;
            //cout<<"rtag:"<<p->data<<endl;
            //前驱的右孩子指向当前节点
            pre->rchild=p;
        }
        pre=p;
        //cout<<pre.data<<" ";
        InThreading(p->rchild);
    }
}

/*
 *建立头节点，二叉树线索化
 */
template <class T>
int InOrderThr(BitNode<T> *(&head) , BitNode<T> *(&t))
{
    if(!(head = new BitNode<T>))
    {
        return 0 ;
    }
    head->LTag = 0 ;
    head->RTag = 1 ;
    head->rchild = head ; //头指针回指
    if(!t)
    {
        head->lchild = head ;
    }
    else
    {
        head->lchild = t ;
        pre = head ;
        InThreading(t) ;
        pre->rchild = head ;
        pre->RTag = 1 ;
        head->rchild = pre ; //将最后一个节点线索化
    }
    return 1 ;
}

//以中序遍历二叉树
template<class T>
void InOrderTraverse_Thr(BitNode<T> *p){
    BitNode<T> *t;
    //t=p;
    //int cnt=0;
    //头指针
    t=p->lchild;
    //循环结束条件
    while(t!=p){
        //找到中序的第一个节点 
        while(t->LTag==0){
            //cout<<"t:"<<t->data<<endl;
            t=t->lchild;
        }
        cout<<t->data<<" ";
        //cnt++;
        //找到后继
        while (t->RTag==1 && t->rchild!=p)
        {
            t=t->rchild;
            cout<<t->data<<" ";
            //cnt++;
        }
        //p进至右子树根
        t=t->rchild;
    }
}


int main(){
    BitNode<char> *head=new BitNode<char>(0);
    BitNode<char> *t=new BitNode<char>(0);
    //以中序创建二叉树
    CreateBiTree(t);
    //cout<<t->rchild->LTag;
    //线索化
    //InThreading(t);
    //cout<<t->data;
    InOrderThr(head,t);
    //遍历
    InOrderTraverse_Thr(head);
}
