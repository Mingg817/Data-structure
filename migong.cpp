#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 30
#define M 8
#define N 8


typedef struct 
{
    int x;
    int y;
} posi;

typedef struct
{
    posi data[MAXSIZE];
    int top;
}stack;

void inistack(stack &L)
{
    L.top=-1;
}

void append(stack &L,int x,int y)
{
    posi a;
    a.x=x;a.y=y;
    L.data[L.top+1]=a;
    L.top+=1;
}

void pop(stack &L)
{
    L.top-=1;
}

posi top_data(stack &L)
{
    return L.data[L.top];
}

int main()
{
    int maps[M+2][N+2]=
{	
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
    int x=1;
    int y=1;
    stack L;
    inistack(L);
    append(L,x,y);  
    do
    {
        
        if (maps[x-1][y]==0)
        {
            
            maps[x-1][y]=-1;            

            x-=1;
            append(L,x,y);
        }
        else if (maps[x][y+1]==0)
        {
            
            maps[x][y+1]=-1;
            
            y+=1;  
            append(L,x,y);
        }
        else if (maps[x+1][y]==0)
        {
            
            maps[x+1][y]=-1;
            
            x+=1;
            append(L,x,y);
        }
        else if (maps[x][y-1]==0)
        {
            
            maps[x][y-1]=-1;
            y-=1;
            append(L,x,y);
        }
        else
        {
            maps[x][y]=-1;
            pop(L);
            x=L.data[L.top].x;
            y=L.data[L.top].y;
        }
    }while(!(top_data(L).x==M&&top_data(L).y==N));
    for (int i=0;i<=L.top;i++)
    {
        printf("(%d,%d)",L.data[i].x,L.data[i].y);
    }
    return 0;
}