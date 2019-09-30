#include <iostream>
#include <stdio.h>
using namespace std;
int dp[2000000];
signed main()
{
	int n,sum=0,i;
	scanf("%d",&n);
	dp[0]=1;
	for (i=0;i<n;++i)
	{
		int a,q;
		scanf("%d",&a);
		sum+=a;
		for (q=min(2000000-a,2000*i);q>=0;--q)
		{
			dp[q+a]|=dp[q];
		}
	}
	for (i=sum/2;i>=0;--i)
	{
		if (dp[i])
		{
			cout<<max(i,sum-i);
			return 0;
		}
	}
}