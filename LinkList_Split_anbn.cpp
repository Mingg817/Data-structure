#include "LinkList.cpp"

int LinkList_Split_anbn(LinkList &L1,LinkList &L2)
{
    //开始拆分
    LinkList L3;
    InitLinkList(L3);
    LinkList p=L1;
    LinkList m=L3;
    int j=0;
    do
    {
        p=p->next;
        m->next=p->next;
        m=m->next;
        j++;
        p->next=p->next->next;   
        m->next=NULL;
    }while(p->next != NULL);
    //开始倒置
    int stor[j];
    p=L3->next;
    for (int i=0;i<j;i++)
    {
        stor[i]=p->data;
        p=p->next;
    }
    InitLinkList(L2);
    p=L2;
    for (int i=j-1;i>=0;i--)
    {
        p->next=(LinkList)malloc(sizeof(Lnode));
        p=p->next;
        p->data=stor[i];
        p->next=NULL;
    }

    return 0;

}

int main()
{
    //input a LinkList
    LinkList L;
    int a;
    int j=0;
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a);
        if (j==0) InitLinkList(L);
        ListInsert(L,j,a);
        j++;
        char c = getchar();
        if (c == '\n') break;
    }
    LinkList L2;
    LinkList_Split_anbn(L,L2);
    print_all_elem(L);
    print_all_elem(L2);
    return 0;
}