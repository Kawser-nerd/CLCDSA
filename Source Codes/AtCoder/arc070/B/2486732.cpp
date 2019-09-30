#include<map>
#include<set>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;

int n,k,a[5010],dp[17][5010],ans;

void solve(int l,int r,int dep)
{
	if(l==r)
	{
		int tmp=0;
		for (int i=max(0,k-a[l]); i<k; ++i)
		{
			tmp|=dp[dep][i];
		}
		ans+=1-tmp;
		return;
	}
	int mid=(l+r)>>1;
	for(int i=0; i<k; ++i)
	{
		dp[dep+1][i]=dp[dep][i];
	}
	for(int i=l; i<=mid; ++i)
	{
		for (int j=k-1; j>=a[i]; --j)
		{
			dp[dep+1][j]|=dp[dep+1][j-a[i]];
		}
	}
	solve(mid+1,r,dep+1);
	for(int i=0; i<k; ++i)
	{
		dp[dep+1][i] = dp[dep][i];
	}
	for(int i=mid+1; i<=r; ++i)
	{
		for(int j=k-1; j>=a[i]; --j)
		{
			dp[dep+1][j]|=dp[dep+1][j-a[i]];
		}
	}

	solve(l,mid,dep+1);
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1 ; i <= n ; ++ i)
	{
		scanf("%d",&a[i]);
	}
	dp[1][0] = 1;
	solve(1,n,1);
	printf("%d\n",ans);
	return 0;
}