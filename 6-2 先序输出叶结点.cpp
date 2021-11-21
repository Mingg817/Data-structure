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
void PreorderPrintLeaves(BinTree BT)
{
    if (BT==NULL)
    {
        return;
    }
    if (BT->Left)
    {
        PreorderPrintLeaves(BT->Left);
    }
    if (BT->Right)
    {
        PreorderPrintLeaves(BT->Right);
    }
    if (BT->Left==NULL && BT->Right==NULL)
    {
        printf(" %c", BT->Data);
    }
}

int main()
{
    BinTree BT = CreatBinTree();
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */