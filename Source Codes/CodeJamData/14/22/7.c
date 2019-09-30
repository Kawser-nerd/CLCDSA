#include <stdio.h>
#include <math.h>
#include <string.h>


int main()
{
	unsigned long long int i,j,k,cnt;
	int T,t;
	unsigned long long int A,B,K;
	
	fscanf(stdin, "%d", &T);
	for(t=1;t<=T;t++)
	{
		fscanf(stdin, "%lld%lld%lld", &A,&B,&K);
		
		cnt=0;

		if(K>=A||K>=B)  cnt=A*B;
		else if(A==B && A==K+1) cnt=A*B-1;		
		else
		{				
			for(i=0;i<A;i++)
			for(j=0;j<B;j++)
			{
				k = i & j;
				if (k<K) cnt++;
				//printf("%lld %lld %lld\n", i,j,k);
			}
		}
		printf("Case #%d: %lld\n", t, cnt);
	}

	return 0;
}
		
		
