#include<stdio.h>
#include<malloc.h>

int main()
{
    int max_size,MAX_SIZE;
    scanf("%d",&max_size);
    MAX_SIZE=max_size;
    int l[max_size];
    for (int i=0;i<max_size;i++)
    {
        scanf("%d",&l[i]);
    }

    int *temp;
    temp=(int *)malloc(sizeof(int)*(max_size+1));
    int temp_len=1; //包括头元素-1
    temp[0]=-1;

    int *max;
    int max_len=0;//不包括头元素-1

    for (int i=0;i<MAX_SIZE;i++)
    {
        if (l[i]>temp[temp_len-1]) 
        //比较当前元素和temp最后一个元素的大小
        {
            temp[temp_len]=l[i];
            temp_len++;
        }
        else
        {
            if (temp_len-1>max_len)
            {
                max=&temp[1];
                max_len=temp_len-1;
                max_size=max_size-max_len;

                //temp=(int *)malloc(sizeof(int)*(max_size+1));
                int temp[max_size+1];
                temp_len=2; //包括头元素-1
                temp[0]=-1;
                temp[1]=l[i];

            }

        }
    }
    if (temp_len==max_size+1 && temp_len-1>max_len)
    {
        max=&temp[1];
        max_len=temp_len-1;
    }

    for(int i=0;i<max_len;i++)
    {
        printf("%d",max[i]);
        if (i!=max_len-1)
        {
            printf(" ");
        }
    }
    
    printf("\ndone");
    return 0;
}