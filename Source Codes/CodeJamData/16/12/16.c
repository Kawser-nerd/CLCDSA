#include <stdio.h>
#define MAX 2500

int main()
{
int T,t,N,n,r;
int s[MAX],p[MAX];

	scanf("%d",&T);
	for (t = 0; t < T; t++)
	{
		scanf("%d",&N);
		
		for (n = 0; n < MAX; n++) s[n] = 0;
		for (n = 0; n < N*(2*N-1); n++)
		{
			scanf("%d",&r);
//			printf("%d ",r);
			s[r-1]++;
		}
		
		printf("Case #%d: ",t+1);
		  for (n = 0; n < MAX; n++)
		  	//printf("%d %d\n",n+1,s[n]);
    		if (s[n] & 1 == 1) printf("%d ",n+1);
		printf("\n");

	}//t
	
	return 0;	
}
