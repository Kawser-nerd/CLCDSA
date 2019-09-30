#include<stdio.h>
#include<string.h>

const int maxn = 100;

int dp[maxn][1<<5][1<<5];
int g[maxn][5];
int ntest,n,m;

int cnt(int x,int y,int z,int p)
{
	if(p<0 || p>=m) return 0;
	else
	{
		int ret = 0;
		if(x&(1<<p)) ret++;
		if(y&(1<<p)) ret++;
		if(z&(1<<p)) ret++;
		return ret;
	}
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&ntest);
	for(int test = 1; test<=ntest; test++)
	{
		scanf("%d%d",&m,&n);
		memset(g,0,sizeof(g));
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&g[j][i]);
		for(int j=0;j<(1<<m);j++)
		{
			if(j&(1<<(m/2))) dp[0][0][j] = 1;
			else dp[0][0][j] = 0;
		}
		for(int i=0;i<=n + 2;i++)
		{
			for(int j=0;j<(1<<m);j++)
				for(int k=0;k<(1<<m);k++)
				{
					if(dp[i][j][k]==-1) continue;
					for(int u = 0;u<(1<<m);u++)
					{
						bool ok = true;
						for(int p=0;p<m;p++)
						{
							if(g[i][p] != cnt(j,k,u,p) + cnt(j,k,u,p+1) + cnt(j,k,u,p-1))
							{
								ok = false; break;
							}
						}
						if(ok)
						{
							int tmp  = dp[i][j][k] + ((u&(1<<(m/2)))?1:0);
							if( dp[i+1][k][u] < tmp)
								dp[i+1][k][u] = tmp;
						}
					}
				}
		}
		int ans = 0;
		for(int i=0;i<(1<<m);i++)
			if(ans < dp[n][i][0])
				ans = dp[n][i][0];
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}
