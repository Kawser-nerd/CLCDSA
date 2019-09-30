#include<stdio.h>
int main()
{	
	int N,i,k;
	int C[500],S[500],F[500],T[500];
	scanf("%d",&N);
	for(i=1;i<N;i++)
	scanf("%d%d%d",&C[i],&S[i],&F[i]);
	for(i=1;i<N;i++)
	{
		T[i]=0;
		for(k=i;k<N;k++)
		{	
			if(T[i]>=S[k]) 
				{
					if((T[i]-S[k])%F[k]==0) 
					T[i]=T[i]+C[k];
					else
					T[i]=T[i]+C[k]+F[k]-(T[i]-S[k])%F[k];
				}
			else
			T[i]=S[k]+C[k];
		}
		printf("%d\n",T[i]);
	}
	printf("0\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&C[i],&S[i],&F[i]);
  ^