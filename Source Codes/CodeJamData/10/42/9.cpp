#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxn = 3000;
const long long inf = 2147483647000000ll;

int n,ntest;
long long dp[maxn][12],v[maxn];
int m[maxn];

long long calc(int u,int watched)
{
	if(u>=(1<<n))
	{
		if(watched>=n-m[u-(1<<n)]) return 0;
		else return inf;
	}
	if(dp[u][watched]!=-1) return dp[u][watched];
	long long res = calc(u*2,watched) + calc(u*2+1,watched);
	long long res2 = calc(u*2,watched+1) + calc(u*2+1,watched+1) + v[u];
	return dp[u][watched] = min(res,res2);
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		scanf("%d",&n);
		for(int i=0;i<(1<<n);i++) scanf("%d",&m[i]);
		int delta = (1<<n);
		for(int k=n-1;k>=0;k--)
		{
			delta -= (1<<k);
			for(int i=0;i<(1<<k);i++)
			{
				int x;
				scanf("%d",&x);
				v[delta + i] = x;
			}
		}
		memset(dp,-1,sizeof(dp));
		long long ans = calc(1,0);
		printf("Case #%d: %I64d\n",test,ans);
	}
	return 0;
}
