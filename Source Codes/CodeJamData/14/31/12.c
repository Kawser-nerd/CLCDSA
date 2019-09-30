#include<stdio.h>
#include<math.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long int T,P,Q,k,i,A,count,m,n;
	float a;
	char c;
	scanf("%lld",&T);
	for(k=1;k<=T;k++)
	{
		count=1;
		scanf("%lld%c%lld",&P,&c,&Q);
		m=Q;n=P;
		while(m%n!=0)
		n=m%n;
		Q/=n;P/=n;
		a=log2(Q);
		A=a;
		//printf("%d %f\n",A,a);
		if(A!=a)
		{
			printf("Case #%lld: impossible\n",k);
			continue;
		}
		while(P*2<Q)
		{
			Q/=2;
			count++;	
		}
		printf("Case #%lld: %lld\n",k,count);
	}
	return 0;
}

