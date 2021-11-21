#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TITLESIZE 20
#define NAMESIZE 5
#define MAXSIZE 100

typedef struct
{
	char subject[TITLESIZE];
	double score;
} sub;

typedef struct student
{
	int num;
	char name[NAMESIZE];
	sub s1, s2, s3, s4;
	double mark;
} stu;

void ave(stu &e)
{
	double a, b, c, d, m;
	a = e.s1.score;
	b = e.s2.score;
	c = e.s3.score;
	d = e.s4.score;
	m = (a + b + c + d) / 4;
	e.mark = m;
}

void unpass(stu a[])
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (a[i].s1.score < 60 || a[i].s2.score < 60 || a[i].s3.score < 60 || a[i].s4.score < 60)
			printf("%s\n", a[i].name);
	}
}

void above90(stu a[])
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (a[i].s1.score > 90)
			printf("%s,s1", a[i].name);
		if (a[i].s2.score > 90)
			printf("%s,s2", a[i].name);
		if (a[i].s3.score > 90)
			printf("%s,s3", a[i].name);
		if (a[i].s4.score > 90)
			printf("%s,s4", a[i].name);
	}
}

int main()
{
	stu *a;
	a=(stu *)malloc(sizeof(stu)*MAXSIZE);

	for (int i = 0; i < MAXSIZE; i++)
	{
		printf("请输入学号：");
		scanf("%d", a[i].num);
		printf("请输入姓名：");
		scanf("%s", a[i].name);
		printf("第一门成绩：");
		scanf("%lf", a[i].s1.score);
		printf("第二门成绩：");
		scanf("%lf", a[i].s2.score);
		printf("第三门成绩：");
		scanf("%lf", a[i].s3.score);
		printf("第四门成绩：");
		scanf("%lf", a[i].s4.score);
		ave(a[i]);
	}

	return 0;
}
