#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAXSIZE 100000

#define true 1
#define ok 1
#define false 0
#define error 0
#define overflow -2
#define infeasible -1


int main()
{
	int n;
	scanf("%d",&n);
	int a[100001];
	for(int j=0;j<n;j++)
	{
		scanf("%d",&a[j]);
	}
	int num=0,start=0,max=0,start1=0,start2=0,end=0;
	while(start<n-1)
	{
		if(a[start+1]>a [start])
		{
			num++;
		}
		else
		{
			if(num>max)
			{
				max=num;
				end=start;
				start2=start1;
			}
			start1=start+1;
			num=0;
		}
		start++;
	}
	if(num==n-1)
	{
		max=num;
	}
	for(int i=0;i<=max;i++)
	{
		printf("%d",a[start2+i]);
		if(i!=max)
		{
			printf(" ");
		}
	}
	return 0;
}


