//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
//#include <set>
//#include <map>
//#include <iostream>

#define ll long long
#define fri(n) for(i=0;i<(n);i++)
#define frj(n) for(j=0;j<(n);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000//10^12

int compare_down(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

int compare_up(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main(void)
{
	//?????
	int n,m;
	int x[100010];
	int kukan[100010];

	//??????
	int i,j,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;


	//????????
	scanf("%d %d",&n,&m);
//	scanf_s("%d %d",&n,&m);

	fri(m){
		scanf("%d",&x[i]);
//		scanf_s("%d",&x[i]);
	}

	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????

	qsort(x, m, sizeof(int), compare_up);
	
	fri(m-1){
		kukan[i]=x[i+1]-x[i];
	}

	qsort(kukan, m-1, sizeof(int), compare_down);

	fri(m-1){
		if(i>=n-1) ans=ans+kukan[i];
	}

	//	printf("??????\n");

	//??

	printf("%d",ans);

	//	printf("???????\n");


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:51:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x[i]);
   ^