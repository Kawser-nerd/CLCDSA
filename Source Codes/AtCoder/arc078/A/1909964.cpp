#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

long long sum[300000];

int main ()
{
	int n;
	long long ans,a;
	scanf ("%d",&n);
	sum[0]=0;
	for (int i=1;i<=n;i++)
	{
		scanf ("%lld",&a);
		sum[i]=sum[i-1]+a;
	}
	ans=abs(sum[1]*2-sum[n]);
	for (int i=2;i<n;i++)
		ans=min(ans,abs(sum[i]*2-sum[n]));
	printf ("%lld\n",ans);
	return 0;
}