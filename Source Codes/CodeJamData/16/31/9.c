#include <stdio.h>

#define MAX_N 26

int maxIndex(int * A, int n)
{
	int i,res,maxVal;

	maxVal=A[0];
	res=0;
	for(i=1;i<n;i++)
		if(A[i]>maxVal)
		{
			maxVal = A[i];
			res = i;
		}
	return res;
}

int main()
{
	int T,tcase,i,P[MAX_N+1],sum,N,a;

	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d",&N);
		sum=0;
		for(i=0;i<N;i++)
		{
			scanf("%d",P+i);
			sum+=P[i];
		}

		printf("Case #%d:",tcase);
		while(sum>0)
		{
			a=maxIndex(P,N);
			P[a]--;
			printf(" %c",'A'+a);
			sum--;
			a=maxIndex(P,N);
			if(2*P[a]>sum || sum>3)
			{
				P[a]--;
				printf("%c",'A'+a);
				sum --;
			}
			a=maxIndex(P,N);
		}
		printf("\n");
	}

	return 0;
}

