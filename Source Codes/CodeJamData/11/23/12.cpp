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
#define INF 0x7fffffff
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

#define FN "C-large"

int gl_colors;

VI go(VVI adj)
{
	int n = SZ(adj);
	bool ok = false;
	bool ok2 = false;
	REP(i,n)
		if (SZ(adj[i]) > 1)
		{
			ok2 = true;
			if (SZ(adj[(i+1)%n]) == 1)
			{
				int ii = (i+1)%n;
				while (SZ(adj[ii]) == 1)
					ii = (ii+1)%n;
				if (find(ALL(adj[ii]),i) == adj[ii].end())
					continue;
				int killed = (ii-i+2*n-1)%n;
				gl_colors = min(gl_colors, killed+2);
				VVI adj2(n-killed, VI());
				REP(qi,n) REP(qj,SZ(adj[qi]))
				{
					int v1 = qi;
					int v2 = adj[qi][qj];
					if (v1 == ii && v2 == i) continue;
					v1 = (v1-ii+n)%n;
					v2 = (v2-ii+n)%n;
					if (v1 < n-killed && v2 < n-killed)
						adj2[v1].pb(v2);
				}
				VI ans = go(adj2);
				VI res(n,-1);
				REP(qi,n)
				{
					int v = (qi-ii+n)%n;
					if (v < n-killed)
						res[qi] = ans[v];
				}
				int clr1 = res[i];
				int clr2 = res[ii];
				int pp = 0;
				REP(qi,n)
				{
					int v = (qi-i+n)%n;
					if (v >= 1 && v <= killed)
					{
						if (res[qi] != -1)
							fprintf(stderr,"ohhh\n");
						while (pp == clr1 || pp == clr2)
							pp++;
						res[qi] = pp < gl_colors ? pp : ((killed - v) %2 == 1 ? clr2 : clr1);
						pp++;
					}
				}
				return res;
			}
		}
	if (ok2)
		fprintf(stderr,"WORST!\n");		
	gl_colors = min(gl_colors,n);
	if (gl_colors < 3)
		fprintf(stderr,"SHIT!\n");
	VI ans(n,0);
	REP(i,n)
		if (i < gl_colors)
			ans[i] = i;
		else
			ans[i] = (i-gl_colors)%2 == 0 ? gl_colors-2 : gl_colors-1;
	return ans;
}

int n,m;
VVI adj;
int uu[2048],vv[2048];

int sh(int x, int b)
{
	return (x-b+n)%n;
}

bool check(VI c)
{
	set<PII> edges;
	REP(ii,n) REP(jj,SZ(adj[ii])) if (edges.count(PII(ii,adj[ii][jj])) == 0)
	{
		set<int> clrs;
		clrs.insert(c[ii]);
		clrs.insert(c[adj[ii][jj]]);
		int prev = ii;
		int cur = adj[ii][jj];
		edges.insert(PII(prev,cur));
		while (cur != ii)
		{
			int mn = -1;
			REP(i,SZ(adj[cur]))
				if (sh(adj[cur][i], cur) < sh(prev, cur) && (mn == -1 || sh(adj[cur][i], cur) > sh(mn, cur)))
					mn = adj[cur][i];
			prev = cur;
			cur = mn;
			if (edges.count(PII(prev,cur)))
				fprintf(stderr,"BAD\n");
			edges.insert(PII(prev,cur));
			clrs.insert(c[cur]);
		}
		if (SZ(clrs) != gl_colors)
			return false;
	}
	return true;
}

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"*");
		scanf("%d%d",&n,&m);
		REP(i,m) scanf("%d",uu+i);
		REP(i,m) scanf("%d",vv+i);
		adj.assign(n,VI());
		REP(i,n) adj[i].pb((i+1)%n);
		REP(i,m)
		{
			--uu[i];
			--vv[i];
			adj[uu[i]].pb(vv[i]);
			adj[vv[i]].pb(uu[i]);
		}
	//if (test != 3) continue;
		gl_colors = INF;
		VI best = go(adj);
		if (!check(best))
			fprintf(stderr,"UUUUUU\n");
		printf("Case #%d: %d\n",test,gl_colors);
		REP(i,n)
			printf(" %d"+(i==0),best[i]+1);
		printf("\n");
	}
	return 0;
}