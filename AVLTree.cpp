/*
 * @Description: 平衡二叉树
 * @Author: Ialboon
 * @Date: 2020-09-14 09:39:43
 * @LastEditTime: 2020-09-16 20:40:00
 * @LastEditors: Ialboon
 */
#include<iostream>
#include "BinaryTree.cpp"
using namespace std;

//对以p为根的二叉排序树作右旋处理
//处理后p指向新的树根节点，即旋转处理之前的左子树的根节点
template <class T>
void R_Rotate(BitNode<T> *(&P)){
    BitNode<T> *L;
    //L指向P的左子树根节点
    L=P->lchild;
    //L的右子树挂接为P的左子树
    P->lchild=L->rchild;
    L->rchild=P;
    //P指向新的根节点
    P=L;
}

template <class T>
void L_Rotate(BitNode<T> *(&P)){
    BitNode<T> *R;
    //R指向P的右子树根节点
    R=P->rchild;
    //R的左子树挂接为P的右子树
    P->rchild=R->lchild;
    R->lchild=P;
    //P指向新的根节点
    P=R;
}

const int LH=1;//左高
const int RH=-1;//右高
const int EH=0;//等高
//对以指针T所指结点为根的二叉树作左平衡旋转处理,此时T的根节点应该是bf的值大于1的数
//本算法结束时，T指向新的根节点
template<class T>
void LeftBalance(BitNode<T> *(&BT)){
    BitNode<T> *L,*Lr;
    //L指向T的左子树根节点
    L=BT->lchild;
    switch (L->bf){
        //检查T的左子树的平衡度，并作相应平衡处理
        //新节点插入在T的左孩子的左子树上，要作单右旋处理
        case LH:
            BT->bf=L->bf=EH;
            R_Rotate(BT);
            break;
        //新节点插入在T的左孩子的右子树上，要作双旋处理（与根节点BF的值符号相反）
        case RH:
            //Lr指向T的左孩子的右子树根
            Lr=L->rchild;
            switch(Lr->bf){
                //修改T及其左孩子的平衡因子
                case LH: BT->bf=RH;
                        L->bf=EH;
                        break;
                case EH: BT->bf=L->bf=EH;
                        break;
                case RH: BT->bf=EH;
                        L->bf=LH;
                        break;
            }
            Lr->bf=EH;
            //对T的左子树作左旋平衡处理
            L_Rotate(BT->lchild);
            //对T作右旋平衡处理
            R_Rotate(BT);
    }
}

//对以指针T所指结点为根的二叉树作右平衡旋转处理,此时T的根节点应该是bf的值小于-1的数
//本算法结束时，T指向新的根节点
template<class T>
void RightBalance(BitNode<T> *(&BT)){
    BitNode<T> *R,*Rl;
    //L指向T的左子树根节点
    R=BT->rchild;
    switch (R->bf){
        //检查BT的右子树的平衡度，并作相应平衡处理
        //新节点插入在T的右孩子的右子树上，要作单左旋处理
        case RH:
            BT->bf=R->bf=EH;
            L_Rotate(BT);
            break;
        //新节点插入在T的右孩子的左子树上，要作双旋处理（与根节点BF的值符号相反）
        case LH:
            //Rl指向BT的右孩子的左子树根
            Rl=R->lchild;
            switch(Rl->bf){
                //修改BT及其右孩子的平衡因子
                case RH: BT->bf=LH;
                        R->bf=EH;
                        break;
                case EH: BT->bf=R->bf=EH;
                        break;
                case LH: BT->bf=EH;
                        R->bf=RH;
                        break;
            }
            Rl->bf=EH;
            //对BT的右子树作右旋平衡处理
            R_Rotate(BT->rchild);
            //对BT作左旋平衡处理
            L_Rotate(BT);
    }
}

//若在平衡的二叉排序树中不存在和e有相同关键字的节点，则插入一个
//数据元素为e的新节点并返回1，否则返回0，若因插入而使二叉排序树失去平衡，则作平衡旋转处理
//taller反映BT长高与否
template<class T>
bool InsertAVL(BitNode<T> *(&BT),int e,bool &taller){
    if(!BT){
        //插入新节点，树长高，置taller为true
        BT=new BitNode<T>;
        BT->data=e;
        BT->lchild=BT->rchild=NULL;
        BT->bf=EH;
        taller=true;
    }
    else
    {
        if(e==BT->data){
            //树中已经存在和e有相同关键字的结点则不再插入
            taller=false;
            return false;
        }
        if(e<BT->data){
            //应继续在BT的左子树中进行递归搜索
            if(!InsertAVL(BT->lchild,e,taller)){//未插入
                return false;
            }
            if(taller)//已插到T的左子树中且左子树长高
            {
                switch(BT->bf){
                    case LH://原本左子树比右子树高，需要左平衡处理
                        LeftBalance(BT);
                        taller=false;
                        break;
                    case EH://原本左右子树等高，现因左子树增高而树增高
                        BT->bf=LH;
                        taller=true;
                        break;
                    case RH://原本左子树比右子树高，需要左平衡处理
                        BT->bf=EH;
                        taller=false;
                        break;
                }
            }
        }
        else{
            //应该在BT的右子树进行搜索
            if(!InsertAVL(BT->rchild,e,taller)){//未插入
                return false;
            }
            if(taller)//已插到T的右子树中且右子树长高
            {
                switch(BT->bf){
                    case LH://原本左子树比右子树高，现在等高
                        BT->bf=EH;
                        taller=false;
                        break;
                    case EH://原本左右子树等高，现因右子树增高而树增高
                        BT->bf=RH;
                        taller=true;
                        break;
                    case RH://原本右子树比左子树高，需要右平衡处理
                        RightBalance(BT);
                        taller=false;
                        break;
                }
            }
        }
        
    }
    return true;
}

int main(){
    int i;
    int a[10]={3,2,1,4,5,6,7,10,9,8};
    BitNode<int> *BT=NULL;
    bool taller;
    for(i=0;i<10;i++){
        taller=false;
        InsertAVL(BT,a[i],taller);
    }
   cout<<BT->data;
}