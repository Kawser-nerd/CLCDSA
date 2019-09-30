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

#define N 2048
int n;
VI a[N];
int bb[N],cc[N];

void edge(int x, int y, bool sw)
{
	if (sw) edge(n-1-x,n-1-y,false);
	else a[y].pb(x);
}

void add(int v[], bool sw)
{
	int last[N];
	FILL(last,-1);
	REP(i,n)
	{
		if (last[v[i]] != -1)
			edge(i,last[v[i]],sw);
		if (last[v[i]-1] != -1)
			edge(last[v[i]-1],i,sw);
		last[v[i]]=i;
	}
}

bool mark[N];
int res[N];

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %d\n",test);
		printf("Case #%d:",test);
		scanf("%d",&n);
		REP(i,n) a[i].clear();
		REP(i,n) scanf("%d",bb+i);
		REP(i,n) scanf("%d",cc+n-1-i);
		add(bb,false);
		add(cc,true);
		REP(i,n) UNIQUE(a[i]);
		CLEAR(mark);
		REP(step,n)
		{
			int sel = -1;
			REP(i,n) if (!mark[i])
			{
				bool ok = true;
				REP(j,SZ(a[i]))
					if (!mark[a[i][j]])
					{
						ok=false;
						break;
					}
				if (ok) 
				{
					sel = i;
					break;
				}
			}
			if (sel == -1) { fprintf(stderr,"SHIT!\n"); continue; }
			mark[sel]=true;
			res[sel]=step;
		}
		REP(i,n)
			printf(" %d",res[i]+1);
		printf("\n");
	}
	return 0;
}