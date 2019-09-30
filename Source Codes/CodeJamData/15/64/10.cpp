#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:32000000")
#include <algorithm>
#include <numeric>
#include <string>
#include <list>
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
#include <unordered_map>

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


class MaxFlow {
public:
	int n,s,t;
	struct Edge {
		int end,next,cap;
		Edge(int e,int ca,int ne) : end(e),next(ne),cap(ca) {}
	};
	vector<int> first,prev;
	vector<bool> mark;
	vector<Edge> a;
	MaxFlow(int nn,int ss,int tt) : n(nn),s(ss),t(tt) { first.assign(n,-1); }
	void add(int v,int u,int cap) {
		a.pb(Edge(u,cap,first[v])); first[v] = SZ(a)-1;
		a.pb(Edge(v,0,first[u])); first[u] = SZ(a)-1;
	}
	bool findPath(int s,int t) {
		queue<int> q;
		mark.assign(n,false); mark[s]=true; q.push(s); prev.assign(n,-1);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int e = first[v]; e!=-1; e=a[e].next)
				if (a[e].cap && !mark[a[e].end]) { // add here e->cap>mnc for scaling!
					mark[a[e].end] = true;
					prev[a[e].end] = e;
					q.push(a[e].end);
				}
		}
		return mark[t];
	}
	void augment(int s,int t,int &res,int cap=1000000) {
		for (int v=t; v!=s; v=a[prev[v]^1].end) cap = min(cap,a[prev[v]].cap);
		res += cap;
		for (int v=t; v!=s; v=a[prev[v]^1].end) a[prev[v]].cap-=cap,a[prev[v]^1].cap+=cap;
	}
	int build() {
		int res=0;
		/* scaling version: for (int mxc = 1<<30; mxc; mxc>>=1) // adjust for problem!!!  */
		while (findPath(s,t)) augment(s,t,res);
		return res;
	}
	VI mincut() // build should be called before!
	{
		VI res;
		REP(i,n) if (mark[i]) for (int e=first[i]; e!=-1; e=a[e].next)
			if (!mark[a[e].end] && (e&1)==0) res.pb(e);
		return res;
	}
};

#define N 128
int n,m,k;
int g[N][N];
PII edge[N*N];

int main(int argc, char **argv)
{
	string FN = "D-small-attempt1";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		scanf("%d%d%d",&n,&m,&k);
		//fprintf(stderr,"%d\n",k);
		REP(i,n) REP(j,n) g[i][j] = i==j?0:100000000;
		MaxFlow mf(n*2, 1, (n-1)*2);
		REP(i,m)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			g[x][y]=g[y][x]=1;
			edge[i]=PII(x,y);
		}
		REP(q,n) REP(i,n) REP(j,n) g[i][j]=min(g[i][j],g[i][q]+g[q][j]);
		REP(i,m)
		{
			int x = edge[i].X;
			int y = edge[i].Y;
			REP(step,2)
			{
				if (g[0][n-1] == g[0][x] + g[x][y] + g[y][n-1])
					mf.add(x*2+1,y*2,100000);
				swap(x,y);
			}
		}
		REP(i,n) if (i!=0&&i!=n-1)
			mf.add(i*2,i*2+1,1);
		int res = g[0][n-1];
		if (k>0)
		{
			res++,k--;
			//printf(" +1 ");
		}
		int cut = mf.build();
		if (cut <= k)
		{
			++res;
			//printf(" +1 ");
		}
		printf("%d\n",res);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}