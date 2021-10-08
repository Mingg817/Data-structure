#define LIST_INIT_SIZT 100
#define LISTINCREMENT 10
#include<malloc.h>
#include<stdio.h>

//定义结构体
typedef struct{ 
    int *elem; //储存空间的基地址
    int length; //当前长度
    int listsize; //当前容量
}SqList;

//初始化操作
int InitList_Sq(SqList &L)
{
    L.elem=(int*)malloc(LIST_INIT_SIZT * sizeof(int));
    //L是传入的变量L的地址，L.elem是结构体的elem方法，malloc是请求空间，返回地址,再强制转换为int的指针
    //tip：指针也要规定是说明数据类型，为了可以读取数据 eg：int *a;a[0];就知道读int字节的数据
    L.length = 0 ;
    //初始空间为0
    L.listsize=LIST_INIT_SIZT;
    //给定的储存空间的大小
    return 1;
}

int DestoryList(SqList &L)
{
    free(L.elem);
    L.length=NULL;
    L.listsize=NULL;
    return 1;
}

//查询操作
int LocateElem_Sq(SqList L,int e,int(*compare)(int,int)) 
//int(*compare)(int,int) 
//——compare 是一个指针， 这个指针指向了一个函数，这个函数的形状就是int x(int , int)，并返回int值
{
    int i=1; //i是移动的指针
    int *p=L.elem; //获取L的初始值
    while(i<L.length && !(*compare)(*p++,e)) 
    //当i小于List长度，即当没有遍历完成的时候
    //(*compare)调用函数,比较(*p，e),p自增1,注意这里的compare并没有具体的实现
    //当小于和比较不成功，继续进行while循环
    {
        i++; //移动指针继续向后移动
    }
    if(i <= L.length) //如果没有循环完就退出，则说明找到了，反之没有找到
    {
        return i;
    }else
    {
        return 0;
    }

}

//插入操作
int ListInsert_Sq(SqList &L,int i,int e) //这里是&L,表示要传入L的地址，即&L
{
    if (i<1 || i>L.length +1 ) return -1;
    if (L.length == L.listsize) //长度等于空间，无法再添加，需要扩容
    {
        L.elem = (int *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(int));
        L.listsize += LISTINCREMENT;
    }
    //指示q的位置
    int *q = &(L.elem[i-1]);
    for (int *p=&(L.elem[L.length-1]);p>=q;p--) //for中p>=q两个指针比较大小，p到了q的位置就停止
    {
        *(p+1)=*p;
    }
    *q=e; //插入e
    ++L.length;//表长增加1
    return 1;
}

int ListDelete_Sq(SqList &L,int i)
{
    if (i<1 || i>L.length) return 0;

    int *p=&(L.elem[i-1]);
    int *q=&(L.elem[L.length-1]);
    for (++p;p<=q;p++)
    {
        *(p-1)=*p; //注意，int指针每加1，在物理变量里加sizof(int)
    }
    --L.length;
    return 1;
}

int ListDelete_all_Sq(SqList &L,int a)
{
    int del_num = 0;
    int *q = &(L.elem[L.length-1]);
    for (int *p=L.elem;p<=(q);p++)
    {
        *(p-del_num)=*(p); 
        //注意！不能在if后面写'*p=*(p+del_num);'
        //要让前面判断完后面再执行移动操作！否则会有问题！！！
        if (*p == a)
        {
            ++del_num;
        }
        //*p=*(p+del_num); ×
    }
    L.length=L.length-del_num;

    return 1;
}

int print_all_elem(SqList L)
{
    int *q = &(L.elem[L.length-1]);
    for (int *p=L.elem;p<=q;p++)
    {
        printf("%d ",*p);
    }
    printf("\n");
    return 1;
}

int main(){
    SqList L; //声明一个L为Sqlist
    InitList_Sq(L);
    //构建1—10的列表
    for (int i = 1 ;i<=10;i++)
    {
        ListInsert_Sq(L,i,i);
    }
    //在3，6位置插入‘1’
    ListInsert_Sq(L,3,1);
    ListInsert_Sq(L,6,1);
    //打印列表元素
    print_all_elem(L);
    //删除所有元素1
    ListDelete_all_Sq(L,1);
    //再次打印元素查看结果
    print_all_elem(L);
}
