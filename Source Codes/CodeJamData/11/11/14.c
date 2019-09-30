#include <stdio.h>




long long int N,PD,PG;
int T;
int main(void)
{
	int i,j;
	int NN;
	int flag=0;
	scanf(" %d",&T);
	for(i=1;i<=T;i++)
	{
		scanf(" %lld %lld %lld",&N,&PD,&PG);
		flag=0;
		if(PG==100)
		{
			if(PD==100) printf("Case #%d: Possible\n",i);
			else printf("Case #%d: Broken\n",i);
			continue;
		}
		/*else if(PG==100) 
		{
			printf("Case#%d: Broken\n",i);
			continue;
		}*/
		if(PG==0)
		{
			if(PD==0) printf("Case #%d: Possible\n",i);
			else printf("Case #%d: Broken\n",i);
			continue;
		}
		/*else if(PG==0) 
		{
			printf("Case#%d: Broken\n",i);
			continue;
		}*/
		if(N>=100) NN=100;
		else NN=N;
		for(j=1;j<=NN;j++)
		{
			if((PD*j)%100==0) {flag=1;break;}
		}
		if(flag) printf("Case #%d: Possible\n",i);
		else printf("Case #%d: Broken\n",i);
	
	}
	return 0;
}
