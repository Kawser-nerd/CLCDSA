#include<stdio.h>
#include<string.h>

const int goal = 1000000;
double dp[1<<16][17];
bool vis[1<<16][17];
int m,x;
double p;

double dfs(int money,int round)
{
	if(money == (1<<round)) return 1;
	if(round==0) return 0;
	if(vis[money][round]) return dp[money][round];
	vis[money][round] = true;
	double res = 0;
	for(int i=(money+1)/2;i<=(1<<(round-1));i++)
	{
		int u = money - i;
		if(u<0) continue;
		double tmp = p*dfs(i,round-1) + (1-p)*dfs(u,round-1);
		if(res < tmp)
			res = tmp;
	}
	return dp[money][round] = res;
}

int main()
{
	freopen("p3.in","r",stdin);
	freopen("p3.out","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		scanf("%d%lf%d",&m,&p,&x);
		int t;
		for(t=0;;t++)
		{
			if((long long)goal*(t+1)>x*(1ll<<m)) break;
		}
		memset(vis,0,sizeof(vis));
		double ans = dfs(t,m);
		fprintf(stderr,"Case #%d: %.6lf\n",test,ans);
		printf("Case #%d: %.6lf\n",test,ans);
	}
	return 0;
}
