#include "LinkList.cpp"
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