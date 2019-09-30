#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i=(a), _b=(b); i>=_b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define INF 1000000000
#define INF_LL 1000000000000000000LL
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int h = 2111;
int n,m, u[h], v[h];

vector<pii> r[h];
vector<vi> p;

int cur;
bool comp (pii x, pii y)
{
	if(x.X < cur)
	{
		if(y.X < cur) return x.X < y.X;
		else return false;
	}
	else
	{
		if(y.X < cur) return true;
		else return x.X < y.X;
	}
}

int ans, col[h];
vi o;

bool eq (int x, int v1, int v2)
{	return x==v1 || x==v2; }

void go (int a, int b)
{
	int l = 0;
	while(r[a][l].X != b) ++l;
	if(l==sz(r[a])-1) return;
	int x = r[a][l].Y;
	o.clear();
	REP(j, ans) if(j!=col[a] && j!=col[b])
		o.pb(j);
	o.pb(col[b]);
	int k = 0;
	REP(i, sz(p[x])) if(!eq(p[x][i], a, b))
	{
		col[p[x][i]] = o[k];
		++k;
		if(k>=sz(o)) k = 0;
	}
	REP(i, sz(p[x])) if(p[x][i]==b)
	{
		int j = (i+1)%sz(p[x]);
		if(col[p[x][j]] == col[b])
			col[p[x][j]] = col[a];
	}
	REP(i, sz(p[x])) if(p[x][i] != a)
		go(p[x][(i+1)%sz(p[x])], p[x][i]);
}

bool y[h];
bool check()
{
	REP(i, sz(p))
	{
		REP(j, ans) y[j] = 0;
		REP(j, sz(p[i])) y[col[ p[i][j] ]] = 1;
		REP(j, ans) if(!y[j]) return false;
	}
	return true;
}

int main()
{
	freopen("c-large.in", "r", stdin); //-small-attempt
	freopen("c-large.out", "w", stdout); //-large
	int T, it=1;
for(scanf("%d", &T); it<=T; ++it)
{
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d", u+i), --u[i];
	REP(i, m) scanf("%d", v+i), --v[i];
	REP(i, n)
	{
		r[i].clear();
		r[i].pb( pii((i+1)%n, -1) );
		r[i].pb( pii((i+n-1)%n, -1) );
	}
	REP(i, m)
	{
		r[u[i]].pb( pii(v[i], -1) );
		r[v[i]].pb( pii(u[i], -1) );
	}
	REP(i, n)
	{
		cur = i;
		sort(all(r[i]), comp);
		//printf("%d:\n", i); REP(j, sz(r[i])) printf("%d ", r[i][j].X); printf("\n");
	}
	p.clear();
	vi a;
	REP(i, n) REP(j, sz(r[i])-1) if(r[i][j].Y == -1)
	{
		a = vi(1, i);
		int x = r[i][j].X, px = i;
		r[i][j].Y = sz(p);
		while(x != i)
		{
			a.pb(x);
			int l = 0;
			while(r[x][l].X != px) ++l;
			l = (l+sz(r[x])-1) % sz(r[x]);
			int tmp = x;
			r[x][l].Y = sz(p);
			x = r[x][l].X;
			px = tmp;
		}
		p.pb(a);
	}
	//REP(i, sz(p)) { REP(j, sz(p[i])) printf("%d ", p[i][j]); printf("\n"); }
	int x = 0;
	REP(i, sz(p)) if(sz(p[i]) < sz(p[x]))
		x = i;
	ans = sz(p[x]);
	CL(col, -1);
	REP(j, sz(p[x])) col[ p[x][j] ] = j;
	REP(i, sz(p[x])) go(p[x][(i+1)%sz(p[x])], p[x][i]);
	if(!check()) printf("!!!!!!!\n\n\n\n\n\n\n");
	printf("Case #%d: %d\n", it, ans);
	REP(i, n) printf("%d ", col[i]+1);
	printf("\n");
}
	return 0;
}
