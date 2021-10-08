#include "LinkList.cpp"

int Split_LinkList(LinkList L,LinkList &L1,LinkList &L2,int i)
{
    InitLinkList(L1);
    InitLinkList(L2);

    ListCopy(L,L1);
    
    LinkList p=L1->next;
    int j=1;
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
    // print_all_elem(L);

    LinkList L1,L2;
    int posi; printf("请填写要切割地方前的节点：");scanf("%d",&posi);
    int state=Split_LinkList(L,L1,L2,posi);
    if (state==1)
    {
        print_all_elem(L);
        print_all_elem(L1);
        print_all_elem(L2);
    }else
    {
        printf("切割超过原链表长度！");
    }
    
    return 0;
}