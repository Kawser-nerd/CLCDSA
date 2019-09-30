#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 50;

char g[maxn][maxn];
int num[maxn][maxn];
int n,m;
int x[maxn*maxn],y[maxn*maxn],cnttree;
bool vis[maxn * maxn];
bool choosed[maxn ][ maxn];
int qx[maxn * maxn ], qy[maxn * maxn];
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
int goalx,goaly;

bool b[maxn][maxn];
int d[maxn][maxn];
int prex[maxn][maxn];
int prey[maxn][maxn];
int ans = 0;

int bfs(int u)
{
	int l = 0,r = 0;
	memset(b,false,sizeof(b));
	qx[r] = x[u]; qy[r] = y[u]; d[x[u]][y[u]] = 0; b[x[u]][y[u]] = true; r++;
	prex[x[u]][y[u]] = -1; prey[x[u]][y[u]] = -1;
	while(l<r)
	{
		int X = qx[l], Y = qy[l]; l++;
		int XX,YY;
		if(g[X][Y]=='T' && vis[num[X][Y]]) 
		{
			goalx = X; goaly = Y;
			return d[X][Y];
		}
		for(int i=0;i<4;i++)
		{
			XX = X + dx[i]; YY = Y + dy[i];
			if(XX<0 || XX>=n || YY<0 || YY>=m || g[XX][YY]=='.' || b[XX][YY] == true) continue;
			b[XX][YY] = true;
			d[XX][YY] = d[X][Y] + 1;
			qx[r] = XX;
			qy[r] = YY;
			prex[XX][YY] = X;
			prey[XX][YY] = Y;
			r++;
		}
	}
	return 2147483647;
}

int visit(int x,int y,int dist)
{
	int ret = 0;
	if(prex[x][y]!=-1) ret = visit(prex[x][y],prey[x][y],dist+1);
	if(!choosed[x][y])
	{
		choosed[x][y] = true;
		return ret + dist;
	}
	return ret;
}

void init()
{
	ans = 0;
	memset(choosed,0,sizeof(choosed));
	memset(vis,0,sizeof(vis));
	vis[0] = true;
	while(true)
	{
		int p = cnttree; int tmp, opt = 2147483647;
		for(int i=0;i<cnttree;i++)
			if(!vis[i] && (tmp = bfs(i)) < opt)
			{
				p = i;
				opt = tmp;
			}
		if(p==cnttree) break;
		bfs(p);
		vis[p] = true;
		ans += visit(goalx,goaly,0);
	}
}

int calcdist(int x,int y)
{
	int l = 0,r = 0;
	memset(b,false,sizeof(b));
	qx[r] = x; qy[r] = y; d[x][y] = 0; b[x][y] = true; r++;
	while(l<r)
	{
		int X = qx[l], Y = qy[l]; l++;
		int XX,YY;
		if(g[X][Y]=='T') return d[X][Y];
		for(int i=0;i<4;i++)
		{
			XX = X + dx[i]; YY = Y + dy[i];
			if(XX<0 || XX>=n || YY<0 || YY>=m || g[XX][YY]=='.' || b[XX][YY] == true) continue;
			b[XX][YY] = true;
			d[XX][YY] = d[X][Y] + 1;
			qx[r] = XX;
			qy[r] = YY;
			r++;
		}
	}
	return 2147483647;
}

void process()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(g[i][j]!='.' && !choosed[i][j])
			{
				ans += calcdist(i,j);
			}
}

int main()
{
	freopen("D2.in","r",stdin);
	freopen("D2.out","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test = 1; test<=ntest; test++)
	{
		scanf("%d%d",&n,&m);
		cnttree = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",&g[i]);
			for(int j=0;j<m;j++)
				if(g[i][j]=='T')
				{
					x[cnttree] = i;
					y[cnttree] = j;
					num[i][j] = cnttree;
					cnttree++;
				}
		}
		init();
		process();
		fprintf(stderr,"%d\n",test);
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}