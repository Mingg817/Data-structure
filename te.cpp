#include<stdio.h>

int main()
{
    int Stack[1000];
    int p = -1;
    do
    {
        p += 1;
        scanf("%d", &Stack[p]);
    } while (Stack[p] != -1);
    
}