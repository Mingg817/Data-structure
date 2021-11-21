#include<stdio.h>
#include<malloc.h>

void input(int a[],int maxnumber)
{
    int inp=0;
    for (int i=0;i<maxnumber;i++)
    {
        scanf("%d",&inp);
        a[i]=inp;
    }
}

void oprate(int a[],int maxnumber)
{
    int *temp=(int *)malloc(sizeof(int)*maxnumber);//
    int temp_size=0;
    temp[0]=a[0];
    temp_size++;
    int Max=0;
    int *p_max;
    for (int i=1;i<maxnumber;i++)
    {
        if (a[i]>temp[i-1])
        {
            temp[temp_size]=a[i];
            temp_size++;
        }
        else 
        {
            if (Max<temp_size)
            {
                Max=temp_size;
                p_max=temp;
            }
            int *temp=(int *)malloc(sizeof(int)*maxnumber);
            temp[0]=a[i];
            temp_size=1;
        }
    }
    if(temp_size==maxnumber)
    {
        Max=temp_size;
        p_max=temp;
    }
    for (int i=0;i<Max;i++)
    {
        printf("%d",*(p_max+i));
        if(i<Max-1) printf(" ");
    }
}

int main()
{
    int maxnumber;
    scanf("%d",&maxnumber);
    int a[5];//
    input(a,maxnumber);
    oprate(a,maxnumber);
   // printf("done");
}