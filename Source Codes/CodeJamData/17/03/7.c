#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int n;
	scanf("%d", &n);
	long long min[100], max[100];
	long long N,k;
	long long a,b,c,d;

	for(long i=0; i<n; i++)
	{
		scanf("%lld %lld",&N, &k);
		//printf("%lld %lld\n",N,k);
		a = 1;
		while(a*2<=k)
			a*=2;
		//printf("%lld\n",a);
		b = k - a;
		//printf("%lld\n",b);
		c = (N - a + 1)/a;
		//printf("%lld\n",c);
		d = (N - a + 1)%a;
		//printf("%lld\n",d);
		if(b>=d)
			c=c-1;
		
		min[i]=c/2;
		max[i]=c-min[i];
	}
	for(int i=0; i<n; i++)
	{
		printf("Case #%d: %lld %lld\n",i+1,max[i], min[i]);
	}

}