#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 3
#define QElemType int

typedef struct{
    QElemType data[MAXSIZE];
    int rear;
    int front;
}Sqqueue;

void InitalSqqueue(Sqqueue &Q)
{
    Q.rear=0;
    Q.front=0;
}

bool EnQuene(Sqqueue &Q,QElemType e)
{
    if ((Q.rear+1)%MAXSIZE==(Q.front)) //队满
    //EnQ的过程是先在rear的位置写数据，然后rear再跳到下一个位置
    //为了保证rear和fount相同位置时只有队空可以出现，所以判断rear后是fount时，直接跳出函数，不会在rear上写数据，所以最后的这个位置是浪费的
    //可用的位置是MAXSIZE-1
    {
        return false;
    }
    Q.data[(Q.rear)%MAXSIZE]=e;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return true;
}

bool DeQuene(Sqqueue &Q,QElemType &e)
{
    if (Q.rear==Q.front) //队空
    {
        return false;
    }
    e=Q.data[(Q.front)%MAXSIZE];
    Q.front=(Q.front+1)%MAXSIZE;
    return true;
}
