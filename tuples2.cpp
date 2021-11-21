//稀疏矩阵的三元组表示-算法
#include <stdio.h>
#define MaxSize  100         //矩阵中非零元素最多个数
typedef int ElemType;
typedef struct
{
	int r;					//行号
	int c;					//列号
	ElemType d;				//元素值
} Triple;					//三元组定义
typedef struct 
{	
	int rows;				//行数
	int cols;				//列数
	int nums;				//非零元素个数
	Triple data[MaxSize];
} TSMatrix;					//三元组顺序表

void CreatMat(TSMatrix &t)  //从一个二维稀疏矩阵创建其三元组表示
{
	int M,N,i,j,k,a,s;
	printf("矩阵行数m：");
	scanf("%d",&M);
	printf("矩阵列数n：");
	scanf("%d",&N);
	printf("矩阵非零元素个数i：");
	scanf("%d",&i);
	t.rows=M;t.cols=N;t.nums=i;
	a=0; //a is count number
	while (a<i)
	{	
		printf("非零元素所在行：");
		scanf("%d",&j);
		printf("非零元素所在列：");
		scanf("%d",&k);
		printf("非零元素的值：");
		scanf("%d",&s);
		t.data[a].r=j;
		t.data[a].c=k;
		t.data[a].d=s;
		a++;
	}
}


void DispMat(TSMatrix t)		//输出三元组
{
	int i;
	if (t.nums<=0)			//没有非零元素时返回
		return;
	printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
	printf("\t------------------\n");
	for (i=0;i<t.nums;i++)
		printf("\t%d\t%d\t%d\n",t.data[i].r,t.data[i].c,t.data[i].d);
}

void TranTat(TSMatrix t,TSMatrix &tb)		//矩阵转置
{
	int p,q=0,v;					//q为tb.data的下标
	tb.rows=t.cols;tb.cols=t.rows;tb.nums=t.nums;
	if (t.nums!=0)					//当存在非零元素时执行转置
	{
		for (v=0;v<t.cols;v++)		//tb.data[q]中的记录以c域的次序排列
			for (p=0;p<t.nums;p++)	//p为t.data的下标
				if (t.data[p].c==v+1)
				{
					tb.data[q].r=t.data[p].c;
					tb.data[q].c=t.data[p].r;
					tb.data[q].d=t.data[p].d;
					q++;
				}
	}
}

void FastTransposeSMatris(TSMatrix H,TSMatrix &T)
{
	T.rows=H.cols;
	T.cols=H.rows;
	T.nums=H.nums;
	int numb[H.cols];
	int cpot[H.cols];
	//注意：以上写法会报错,C语言申请变量是在运行初，此时H成员的值并不确定！可以使用malloc创建
	// int numb[N];
	// int cpot[N]; //cpot[x]=n代表着第x列对应转置后在三元组中的第n个
	for (int i=0;i<H.cols;++i) 
	{
		numb[i]=0;
	}
	for (int i=0;i<H.nums;++i)
	{
		numb[H.data[i].c]++;
	}

	cpot[0]=1;
	for (int i=1;i<H.cols;++i)
	{
		cpot[i]=cpot[i-1]+numb[i-1];
	}

	for (int i=0;i<H.nums;++i)
	{
		int posi=cpot[H.data[i].c]-1;
		T.data[posi].d=H.data[i].d;
		T.data[posi].r=H.data[i].c;
		T.data[posi].c=H.data[i].r;
		cpot[H.data[i].c]+=1;
	}
}

int main()
{
	TSMatrix t,tb,puls;
	CreatMat (t);
	printf("b:\n"); DispMat(t);
	TranTat(t,tb);
	printf("tb:\n"); DispMat(tb);
	FastTransposeSMatris(t,tb);
	printf("tb_FAST:\n"); DispMat(tb);
	return 1;
}
