#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <cstring>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 82
int n;
int w[N];
VI g[N];
int par[N];
int lev[N];
bool pmark[N][N][N];
bool vmark[N][N][N];
int mem[N][N][N][N];

void dfs(int v, int p, int lvl)
{
	par[v] = p;
	lev[v] = lvl;
	REP(i,SZ(g[v]))
		if (g[v][i]!=p)
			dfs(g[v][i],v,lvl+1);
}

int go(int xs, int ys, int x, int y, bool skip = false)
{
	int& res = mem[xs][ys][x][y];
	if (res != -INF) return res;
	VI moves;
	if (xs == n)
	{
		REP(i,n)
			moves.pb(i);
	}
	else
	{
		if (ys == n) fprintf(stderr,"BAD\n");
		REP(ii,SZ(g[x]))
		{
			int v = g[x][ii];
			int e = par[x]==v ? x : v;
			if (!pmark[xs][x][e] && !pmark[ys][y][e])
				moves.pb(v);
		}
	}
	if (!moves.empty())
	{
		res = -INF;
		REP(ii,SZ(moves))
		{
			int v = moves[ii];
			res = max(res, (!vmark[xs][x][v]&&!vmark[ys][y][v] ? w[v] : 0) - go(ys,xs==n?v:xs,y,v));
		}
		return res;
	}
	else
	{
		if (skip)
			return res=0;
		return res= -go(ys,xs,y,x,true);
	}
}

int main(int argc, char **argv)
{
	string FN = "D-small-attempt0";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		scanf("%d",&n);
		REP(i,n) scanf("%d",w+i);
		lev[0]=0;
		REP(i,n) g[i].clear();
		REP(i,n-1)
		{
			int x;
			scanf("%d",&x);
			--x;
			g[x].pb(i);
			g[i].pb(x);
		}
		dfs(0,-1,0);
		CLEAR(pmark);
		CLEAR(vmark);
		REP(i,n) REP(j,n)
		{
			int x = i, y = j;
			while (lev[x] > lev[y])
			{
				vmark[i][j][x]=pmark[i][j][x]=true;
				x=par[x];
			}
			while (lev[x] < lev[y])
			{
				vmark[i][j][y]=pmark[i][j][y]=true;
				y=par[y];
			}
			while (x!=y)
			{
				vmark[i][j][x]=pmark[i][j][x]=true;
				vmark[i][j][y]=pmark[i][j][y]=true;
				x=par[x];
				y=par[y];
			}
			vmark[i][j][x]=true;
		}
		REP(i,n+1) REP(j,n+1) REP(ii,n+1) REP(jj,n+1) mem[i][j][ii][jj]=-INF;
		int res = go(n,n,n,n);
		printf("%d\n",res);
		fflush(stdout);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}