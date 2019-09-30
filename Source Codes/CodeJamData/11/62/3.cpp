#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<complex>

using namespace std;

const long long inf = 1000000000000000000ll;
const double eps = 1e-9;
const double pi = acos(-1.0);

long long n, m, k;
long long g[25][25];
bool vis[25][25];

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

/*
void dfs(int x, int y, int v)
{
	if(vis[x][y]) return;
	vis[x][y] = true;

	if(w[x][y] < v) w[x][y] = v;

	for(int i=0; i<4; i++)
	{
		if(x+dx[i]<0 || x+dx[i]>=n || y+dy[i]<0 || y+dy[i]>=m) continue;
		if(w[x+dx[i]][y+dy[i]] <= w[x][y])
			dfs(x+dx[i],y+dy[i],v);
	}
}

set<pair<int, pair<int,int> > > T;

void simulation()
{
	memset(vis, 0, sizeof(vis));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			T.insert(make_pair(g[i][j], make_pair(i, j)));
			if(i==0 || j==0 || i==n-1 || j==m-1) vis[i][j] = true;
		}

	while(!T.empty())
	{
		int x = T.begin()->second.first;
		int y = T.begin()->second.second;
		if(ans < T.begin()) ans = T.begin();
		T.erase(T.begin());

		vis[x][y] = true;
		for(int i=0;i<4;i++)
		{
			if(x+dx[i]<0 || x+dx[i]>=n || y+dy[i]<0 || y+dy[i]>=m) continue;
			if(vis[x+dx[i]][y+dy[i]]) continue;
			if(g[x+dx[i]][y+dy[i]] < g[x][y]+1)
			{
				T.erase(make_pair(g[x+dx[i]][y+dy[i]],make_pair(x+dx[i],y+dy[i])));
				g[x+dx[i]][y+dy[i]] = g[x][y]+1;
				T.insert(make_pair(g[x+dx[i]][y+dy[i]],make_pair(x+dx[i],y+dy[i])));
				vis[x+dx[i]][y+dy[i]] = true;
			}
		}
	}
}
*/

long long Next;

void dfs(int x, int y, long long h)
{
	if(x<0 || y<0 || x>n || y>m || vis[x][y]) return;
	vis[x][y] = true;
	if(g[x][y]<h)
	{
		for(int i=0; i<4; i++)
			dfs(x+dx[i], y+dy[i], h);
	}
	else
	{
		if(Next > g[x][y])
			Next = g[x][y];
	}
}

long long simulation()
{
	n++; m++;
	for(long long height=1;height<inf;)
	{
		memset(vis, 0, sizeof(vis));
		Next = inf;

		dfs(0, 0, height);

		for(int i=0; i<=n; i++)
			for(int j=0; j<=m; j++)
				if(!vis[i][j] && g[i][j]!=0 && g[i][j]<=Next)
					g[i][j]=Next+1;

		height = Next+1;
		fprintf(stderr, "%I64d\n", height);
	}

	long long ans = 0;
	for(int i=0; i<=n; i++)
		for(int j=0; j<=m; j++)
			if(ans < g[i][j])
				ans = g[i][j];
	return ans;
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test=1; test<=ntest; test++)
	{
		memset(g, 0, sizeof(g));
		scanf("%I64d%I64d%I64d", &n, &m, &k);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				scanf("%I64d", &g[i][j]);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				g[i][j] = (g[i][j] + k - 1) / k;
		
		long long ans = simulation();
		printf("Case #%d: %I64d\n", test, ans);
	}
	return 0;
}