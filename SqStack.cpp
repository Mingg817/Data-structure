#include<malloc.h>
#include<stdio.h>
#define STACK_INIT_SIZE 100
#define STACKINCREAMENT 10

typedef struct
{
    int *base;
    int *top;
    int stacksize;
}SqStack;

int InitStack(SqStack &S)
{
    S.base=(int*)malloc(STACK_INIT_SIZE*(sizeof(int)));
    //注意(int*) sizeof(int)
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
}

int Push(SqStack &S,int e)
{
    if (S.top-S.base>=S.stacksize)
    {
        S.base=(int*)realloc(S.base,(S.stacksize+STACKINCREAMENT)*sizeof(int));
        if(!S.base) return -1;
        //判断是否分配成功
        S.top=S.base+S.stacksize;
        //注意别忘了栈底改了栈顶也要更改！
        S.stacksize+=STACKINCREAMENT;
    }
    * S.top=e;
    S.top+=1;

    return true;
}

int Pop(SqStack &S,int &e)
{
    if (S.top==S.base) return false;
    //判断是否为空栈
    e=*S.top;
    S.top=S.top-1;
    return 1;
}

int print_all_stack(SqStack S)
{
    int *q=S.base;
    while(!(q==S.top))
    {
        printf("%d",*q);
        q++;
    }
    
}

int main()
{
    SqStack S;
    InitStack(S);
    Push(S,10);
    print_all_stack(S);
    int e;
    Pop(S,e);
    print_all_stack(S);

    return 0;
}