#include<stdio.h>
#include<string.h>

int dp[3][1<<16];
int n,m;
char g[30][30];

int main()
{
	freopen("E2.in","r",stdin);
	freopen("E2.out","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test = 1 ; test <= ntest; test++)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%s",&g[i]);
		for(int i=0;i<(1<<m);i++) dp[0][i] = -100000000;
		dp[0][0] = 0; int cur = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				for(int s=0;s<(1<<m);s++) dp[cur^1][s] = -100000000;
				for(int s=0;s<(1<<m);s++)
				{
					if(dp[cur][s]<=-100000000) continue;
					if(g[i][j]!='#')
					{
						if(dp[cur^1][s&(~(1<<j))] < dp[cur][s]) 
							dp[cur^1][s&(~(1<<j))] = dp[cur][s];
					}
					if(g[i][j]!='.')
					{
						int tmp = 0;
						if(j>0 && (s&(1<<(j-1)))!=0) tmp++;
						if((s&(1<<j))!=0) tmp++;
						if(dp[cur^1][s|(1<<j)] < dp[cur][s] + 4 - tmp * 2) 
							dp[cur^1][s|(1<<j)] = dp[cur][s] + 4 - tmp * 2;
					}
				}
				cur ^= 1;
			}
		int ans = 0;
		for(int i=0;i<(1<<m);i++) 
			if(ans < dp[cur][i]) 
			{
				ans = dp[cur][i];
			}
			printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}