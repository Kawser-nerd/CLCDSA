#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:32000000")
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

#define N 1024000
int n,d,s[N],p[N];
VI adj[N];
int l[N],r[N];
int delta[N];

void read(int s[])
{
	int a,c,r;
	scanf("%d%d%d%d",&s[0],&a,&c,&r);
	REP(i,n) if (i)
	{
		s[i] = (s[i-1]*(LL)a+c)%r;
	}
}

void dfs(int v, int ll, int rr)
{
	ll = max(ll,s[v]-d);
	rr = min(rr,s[v]);
	l[v]=ll;
	r[v]=rr;
	REP(i,SZ(adj[v]))
		dfs(adj[v][i],ll,rr);
}

int main(int argc, char **argv)
{
	string FN = "A-large";
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
		scanf("%d%d",&n,&d);
		read(s);
		read(p);
		REP(i,n) if (i) p[i]%=i;
		REP(i,n) adj[i].clear();
		REP(i,n) if (i) adj[p[i]].push_back(i);
		dfs(0,0,N-2);
		CLEAR(delta);
		REP(i,n) if (l[i]<=r[i]) delta[l[i]]++,delta[r[i]+1]--;
		int res = 0;
		int sum = 0;
		REP(i,N)
		{
			sum += delta[i];
			res=max(res,sum);
		}
		printf("%d\n",res);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}