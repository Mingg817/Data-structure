#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0

#define stackinitsize 100
#define stackincrement 10
typedef struct Node{
    int *base;
    int *top;
    int stacksize;
}Sqstack;

int InitStack(Sqstack &s)
{
	s.base =(int*)malloc(stackinitsize*sizeof(int));
	if(!s.base )
	{
		return OVERFLOW;
	}
	else
	{
		s.top =s.base ;
		s.stacksize ==stackinitsize;
		return OK;
	}
}//¹¹Ôì¿ÕÕ»


float Push (Sqstack &s,float e)
{
	if(s.top -s.base >=s.stacksize )
	{
		s.base =(int*)realloc(s.base ,(s.stacksize +stackincrement)*sizeof(int));
		if(!s.base )
		{
			return ERROR;
		}
		s.top =s.base +s.stacksize ;
		s.stacksize +=stackincrement;
	}
	*s.top++=e;
	return OK;
}//ÈëÕ»
float GetTop(Sqstack S,float &e)
{
    if(S.top==S.base)
        return ERROR;
    else
        return e=*(S.top-1);
}

float Pop(Sqstack &S,float &e)
{
    if(S.top==S.base)
        return ERROR;
    else
        return e=*--S.top;
}

float sum(char s[],int len)
{
    int i;
	float x1,x2,n=1;
    float e;
    Sqstack s2;
    InitStack(s2);
    for(i=len-1;i>=0;i--)
    {
        if('0'<=s[i]&&s[i]<='9')
            Push(s2,s[i]-'0');
        else 
		{
            Pop(s2,x2);
            Pop(s2,x1);
            switch(s[i])
            {
                case '+':n=x1+x2;
				break;
                case '-':n=x2-x1;
				break;
                case '*':n=x1*x2;
				break;
                case '/':{
                if(x1==0)
                	{
                    	// cout<<ERROR<<endl;
                    	return ERROR;
					}
                    else
                    { 
						n=x2/x1;
						break;
					}
                }
            }
            Push(s2,n);
        }
    }
    GetTop(s2,e);
    return e;
}

int main()
{
    char s[30];
	int len;
    float n;
    scanf("%s",s);
    len=(int)strlen(s);
    n=sum(s,len);
    printf("%.1f\n",n);
    return 0;
}
