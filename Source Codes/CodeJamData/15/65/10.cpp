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

#define N 128

int n,m;
int a[N][N];
map<int,VI> cl;

int st[N];

void apply(int xx)
{
	REP(j,m)
	{
		st[j] = max(0,st[j]+a[xx][j]);
	}
}

int total() {
	int s = 0;
	REP(i,m) s+= st[i];
	return s;
}

int main(int argc, char **argv)
{
	string FN = "E-small-attempt0";
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
		scanf("%d%d",&n,&m);
		REP(i,n) REP(j,m) scanf("%d",&a[i][j]);
		cl.clear();
		REP(i,n)
		{
			int mask = 0;
			REP(j,m) if (a[i][j] >= 0) mask |= 1<<j;
			int s = 0;
			REP(j,m) s+=a[i][j];
			if (s>=0) mask |= 1<<m;
			cl[mask].pb(i);
		}
		VI order;
		for (const auto& it : cl) order.push_back(it.first);
		SORT(order);
		int res = 0;
		do
		{
			CLEAR(st);
			REP(ii,SZ(order)) for (int ind : cl[order[ii]])
				apply(ind);
			res = max(res,total());
		} while (next_permutation(ALL(order)));
		printf("%d\n",res);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}