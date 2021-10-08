#include "LinkList.cpp"
int main()
{
    LinkList L;
   // InitLinkList(L);

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
    print_all_elem(L);
    return 0;   
}