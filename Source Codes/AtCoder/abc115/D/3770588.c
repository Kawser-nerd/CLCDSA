#include <stdio.h>

long long pate(long long burger[], long long p[], int n, long long x);

int main(void)
{
	int n;
	long long x, p[51], burger[51], ans;
	scanf("%d%lld", &n, &x);
	p[0]=1;
	burger[0]=1;
	for (int i = 1; i <= n; ++i) p[i]=2*p[i-1]+1;
	for (int i = 1; i <= n; ++i) burger[i]=2*burger[i-1]+3;
	ans=pate(burger, p, n, x);
	printf("%lld\n", ans);
	return 0;
}

long long pate(long long burger[], long long p[], int n, long long x)
{
	long long ans;
	if (x>=burger[n]-n)
	{
		ans=p[n];
	}
	else if (x>burger[n-1]+2)
	{
		x=x-burger[n-1]-2;
		ans=p[n-1]+pate(burger, p, n-1, x)+1;
	}
	else if (x==burger[n-1]+2)
	{
		ans=p[n-1]+1;
	}
	else if (x>n)
	{
		ans=pate(burger, p, n-1, x-1);
	}
	else
	{
		ans=0;
	}
	return ans;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%lld", &n, &x);
  ^