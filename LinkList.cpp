#include<malloc.h>
#include<stdio.h>

typedef struct Lnode
{
    int data; //数据域
    struct Lnode *next; //指针域
}Lnode,*LinkList;

int InitLinkList(LinkList &L) //必须初始化，即给空节点空间和空节点的next地址要规定NULL
{
    L=(LinkList)malloc(sizeof(Lnode));
    L->next=NULL;
    return 1;
}

int GetElem_L(LinkList L,int i)
{
    LinkList p=L->next; //p指向头节点L的next，即指向第一个节点
    int j = 1; //j指示当前p的节点序号
    while(p && j<i ) //将p指向第i个元素 j<i因为在i-1节点时，p指向next，此时p就已经指向了第i个节点
    {
        p=p->next;
        j++;
    }

    if (!p || j>i)
    {
        return -1;
    }
    else{
        return p->data;
    }

}
int ListInsert(LinkList &L,int i,int e) //在i后面插入
{
    LinkList p=L;
    int j=0; //注意，这里p不需要指向头节点的next，而且j=0，因为我们可以在第一位上Insert元素
    while(p && j<i)//指向i号元素
    {
        p=p->next;
        j++;
    }

    //LinkList s;//错！不是这样添加节点
    LinkList s = (LinkList)malloc(sizeof(Lnode));
    s->data=e;

    s->next=p->next;
    p->next=s;

    return 1;
}

int ListDelete(LinkList &L,int i)
{
    LinkList p=L;
    int j = 0;
    while(p && j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!(p->next) || j>i-1)
    {

        printf("!!删除元素超过List长度!!");
        return -1;
    }
    LinkList deled_addr=p->next;
    p->next=p->next->next;
    free(deled_addr);
    return 1;
}

int ListCopy(LinkList L,LinkList &L1)
{
    InitLinkList(L1);
    LinkList p1=L;
    LinkList p2=L1;
    while(p1->next)
    {
        LinkList s=(LinkList)malloc(sizeof(Lnode));
        s->data=p1->next->data;
        p2->next=s;

        p1=p1->next;
        p2=p2->next;

    }
    p2->next=NULL;
    return 1;
}

int Split_LinkList(LinkList L,LinkList &L1,LinkList &L2,int i)
{
    if (i<0) return -1;

    InitLinkList(L1);
    InitLinkList(L2);

    ListCopy(L,L1);
    
    LinkList p=L1;
    int j=0;
    while(p && j<i)
    {
        p=p->next;
        j++;
    }
    if(!p)
    {
        return -1;
    }
    L2->next=p->next;
    p->next=NULL;

    return 1;
}

int print_all_elem(LinkList L)
{
    LinkList p=L->next;
    while (p)
    {
        printf("%d ",(int)(p->data));
        //cout <<  " " << dec << p->data << " " << endl;
        p=p->next;
    }
    printf("\n");   
    return 1;
}

