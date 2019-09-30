#include <stdio.h>
#include <math.h>

int main()
{
	long long i,L,P,C,T,z,p[55];
	
	p[0] = 0;
	for(i=1;i<=50;i++)
		p[i] = p[i/2]+1;

	scanf("%lld",&T);
	for(z=1;z<=T;z++)
	{
		scanf("%lld %lld %lld",&L,&P,&C);

		for(i=0;L*((long long)pow((long double)C,i))<P;i++);
		

		printf("Case #%lld: %lld\n",z,p[i-1]);
	}
	return 0;
}
