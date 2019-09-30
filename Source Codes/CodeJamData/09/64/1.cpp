#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 500 + 10;
const int INF = 1<<29;

int x[maxn],y[maxn],r[maxn],ss[maxn];
int tr[maxn],g[maxn][maxn];
int n;
int tt;

inline int sqr( int x )
{
	return x*x;
}
int q[maxn];
int dis[maxn];
bool BFS()
{
	for(int i=1;i<=tt;i++) dis[i] = INF;
	dis[tt] = 0;
	int l=0,r=1;
	q[1] = tt;
	int x;
	while( l<r )
	{
		x = q[++l];tr[x] = 1;
		for(int i=1;i<=tt;i++) if( dis[i]==INF && g[i][x] )
			dis[ q[++r] = i ] = dis[x] +1;
	}
	return dis[1]!=INF;
}
int dfs( int x,int nowd )
{
	if( x==tt ) return nowd;

	int z,cur = 0;
	for( int &i = tr[x];i<=tt;i++ ) if( g[x][i] && dis[i]==dis[x]-1 )
	{
		z = dfs(i,min(g[x][i],nowd));
		if(z)
		{
			g[x][i]-=z;
			g[i][x]+=z;
			cur+=z;
			nowd-=z;
			if(nowd==0) break;
		}
	}

	if(cur==0) dis[x] = INF;
	return cur;
}
int main()
{
	int T;
	scanf("%d",&T);
	int ans;
	for( int num=1;num<=T;num++ )
	{
		scanf("%d",&n);
		tt = n+2;
		for(int i=1;i<=tt;i++)
		for(int j=1;j<=tt;j++) g[i][j] = 0;

		for(int i=1;i<=n;i++)
			scanf("%d%d%d%d",x+i,y+i,r+i,ss+i);

		for(int i=1;i<=n;i++) if( ss[i]>=0 )
			g[1][i+1] = ss[i];else
			g[i+1][tt] = -ss[i];

		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(i!=j && sqr(x[i]-x[j])+sqr(y[i]-y[j]) <= sqr(r[i]) )
			g[i+1][j+1] = INF;

		ans = 0;
		for(int i=1;i<=n;i++) if(ss[i]>0) ans+=ss[i];
		while( BFS() ) ans-=dfs(1,INF);
		printf("Case #%d: %d\n",num,ans);
	}
	return 0;
}
