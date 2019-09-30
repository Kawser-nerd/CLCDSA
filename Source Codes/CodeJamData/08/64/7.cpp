#include<stdio.h>
#include<map>
#include<set>

using namespace std;

const int maxn = 300;

int g[maxn][maxn];
int x[maxn],y[maxn],p[maxn],u[maxn];
int n,m;
bool ok;

void dfs(int o)
{
	if(ok) return;
	if(o==m+1)
	{
		bool t = true;
		for(int i=1;i<m;i++)
			if(g[ p[x[i]] ][ p[y[i]] ]==0)
				t = false;
		if(t) ok = true;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!u[i])
		{
			p[o]=i;
			u[i]=true;
			dfs(o+1);
			u[i]=false;
		}
}

int main()
{
	freopen("p4.in","r",stdin);
	freopen("p4.out","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		memset(g,0,sizeof(g));
		scanf("%d",&n);
		for(int i=1,tx,ty;i<n;i++)
		{
			scanf("%d%d",&tx,&ty);
			g[tx][ty]=g[ty][tx]=1;
		}
		scanf("%d",&m);
		for(int i=1;i<m;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		ok = false;
		memset(u,0,sizeof(u));
		dfs(1);
		if(ok) printf("Case #%d: YES\n",test);
		else printf("Case #%d: NO\n",test);
	}
	return 0;
}
