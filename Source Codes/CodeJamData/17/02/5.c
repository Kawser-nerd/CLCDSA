#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int sat(long long a)
{
	int l=9;
	while(a!=0)
	{
		if(a%10<=l)
		{
			l = a%10;
			a/=10;
		}
		else
			return 0;
	}
	return 1;
}
int main()
{
	int n;
	scanf("%d", &n);
	long long a[100];
	long long b;

	for(long i=0; i<n; i++)
	{
		scanf("%lld",&b);
		//printf("%lld\n",b);
		a[i]=b;
		for(long long j=1; !sat(a[i]) ; j*=10)
		{
			a[i] = (b/j)*j-1;
		}
	}
	for(int i=0; i<n; i++)
	{
		printf("Case #%d: %lld\n",i+1,a[i]);
	}

}