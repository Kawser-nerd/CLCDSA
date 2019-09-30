#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int N;
int P,K,L;
int F[1000];

void QuickSort(int A[],int i1,int i2)
{
	int i,j;
	int temp;					
	if(i1>=i2)return ;
	for(i=i1,j=i1+1;j<=i2;j++)
	{
		if(A[j]>A[i1])			/*从小到大排序*/
		{
			i++;
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	temp=A[i1];
	A[i1]=A[i];
	A[i]=temp;
	QuickSort(A,i1,i-1);
	QuickSort(A,i+1,i2);
}


int main()
{
	int No,i,j;
	long long s;
	long long t1,t2;
	scanf("%d",&N);
	for(No=1;No<=N;No++)
	{
		scanf("%d%d%d",&P,&K,&L);
		for(i=0;i<L;i++)
		{
			scanf("%d",F+i);
		}
		if(P*K<L)
		{
			printf("Case #%d: Impossible\n",No);
			continue;
		}
		QuickSort(F,0,L-1);
		s=0;
		for(i=0;i<L;i++)
		{
			t1=(i/K+1);
			t2=F[i];
			s+=t1*t2;
		}
		printf("Case #%d: %lld\n",No,s);
	}
	return 0;
}
