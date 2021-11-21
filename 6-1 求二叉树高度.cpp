#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight(BinTree BT)
{
    if (BT==NULL)
        return 0;
    int max_h=1;
    int Left=0, Right=0;
    if (BT->Left)
    {
        Left=GetHeight(BT->Left);
    }       
    if (BT->Right)
    {
        Right=GetHeight(BT->Right);
    }
    if (Left>Right)
    {
        max_h += Left;
    }else{
        max_h += Right;
    }   
    return max_h;
}

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}
/* 你的代码将被嵌在这里 */