#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

ll n,m,x,y,k,num[110],h,dp[25000],cnt,d2[25000],ans;

int main()
{
	ll i,j;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	}
	sort(num+1,num+n+1);
	dp[0]=d2[0]=1;
	for(i=1;num[i]<k&&i<=n;i++)
	{
		num[i]=k-num[i];
		for(j=3000;j>=num[i];j--)
		{
			dp[j]+=dp[j-num[i]];
		}
	}
	for(;num[i]==k&&i<=n;i++) cnt++;
	for(;i<=n;i++)
	{
		num[i]-=k;
		for(j=3000;j>=num[i];j--)
		{
			d2[j]+=d2[j-num[i]];
		}
	}
	for(i=0;i<=3000;i++)
	{
		ans+=dp[i]*d2[i]*(1ll << cnt);
	}
	cout<<ans-1;
}