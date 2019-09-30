#include<iostream>
#include<cstdio>
#include<cstring>
#define N 5010
using namespace std;

int n,k,dp[20][N],num[N],ans;

void sol(int l,int r,int now)
{
	if(l==r)
	{
		int i;
		for(i=max(0,k-num[l]); i<k; i++)
		{
			if(dp[now][i]) break;
		}
		if(i<k) ans++;
		return;
	}
	int i,j,mid=((l+r)>>1);
	for(i=0;i<k;i++) dp[now+1][i]=dp[now][i];
	for(j=l; j<=mid; j++)
	{
		for(i=k-1; i>=num[j]; i--)
		{
			dp[now+1][i]|=dp[now+1][i-num[j]];
		}
	}
	sol(mid+1,r,now+1);
	for(i=0;i<k;i++) dp[now+1][i]=dp[now][i];
	for(j=mid+1;j<=r;j++)
	{
		for(i=k-1;i>=num[j];i--)
		{
			dp[now+1][i]|=dp[now+1][i-num[j]];
		}
	}
	sol(l,mid,now+1);
}

int main()
{
	int i,j;
	cin>>n>>k;
	for(i=1; i<=n; i++)
	{
		scanf("%d",&num[i]);
	}
	dp[0][0]=1;
	sol(1,n,0);
	cout<<n-ans;
}