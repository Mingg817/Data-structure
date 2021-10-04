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
    return 0;
}

int print_all_elem(LinkList L)
{
    LinkList p=L->next;
    while (p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");   
    return 1;
}

int main()
{
    LinkList L;
    InitLinkList(L);
    //Creat LinkList
    for (int i=0;i<10;i++)
    {
        ListInsert(L,i,i+1);
    }
    print_all_elem(L);

    //Get Element more one
    for (int i=1;i<12;i++)
    {
        printf("查找第%d个元素:",i);
        int elem = GetElem_L(L,i);
        if (elem != -1)
        {
            printf("%d ",GetElem_L(L,i));
        }
        else
        {
            printf("!!查找超过List长度!!");
        }
        
        printf("\n");
    }
    

    //Del All Linklist more one
    for (int i=0;i<11;i++)
    {
        printf("删除第一个元素:");
        ListDelete(L,1);
        print_all_elem(L);
    }
    return 0;
}