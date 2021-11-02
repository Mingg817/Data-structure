void FastTransposeSMatris(TSMatrix H,TSMatrix &T)
{
	T.rows=H.cols;
	T.cols=H.rows;
	T.nums=H.nums;
	//int numb[H.cols];
	//int cpot[H.cols];
	//注意：以上写法会报错,C语言申请变量是在运行初，此时H成员的值并不确定！可以使用malloc创建
	int numb[N];
	int cpot[N]; //cpot[x]=n代表着第x列对应转置后在三元组中的第n个
	for (int i=0;i<N;++i) 
	{
		numb[i]=0;
	}
	for (int i=0;i<H.nums;++i)
	{
		numb[H.data[i].c]++;
	}

	cpot[0]=1;
	for (int i=1;i<N;++i)
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
