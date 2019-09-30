#include <algorithm>
#include <string>
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

#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define NAME "A-large"
#define AND 1
#define OR 0
#define CONST 2
#define N 11000

int n,rootval,intn;
int type[N];
int changable[N];
bool value[N];

#define left(x) (((x+1)<<1) - 1)
#define right(x) (((x+1)<<1))

int go(int v)
{
	if (v>=intn) return INF;
	int res=INF;
	int l = go(left(v));
	int r = go(right(v));
	REP(chtype,2) REP(chl,2) REP(chr,2)
	{
		if (chtype==1 && changable[v]==0)
			continue;
		int newtype = type[v];
		if (chtype==1) newtype = 1-newtype;
		bool newl = value[left(v)];
		if (chl == 1) newl=!newl;
		bool newr = value[right(v)];
		if (chr == 1) newr=!newr;
		bool newval;
		if (newtype==AND)
			newval=newl&&newr;
		else
			newval=newl||newr;
		if (newval != value[v])
		{
			int cost = 0;
			if (chtype==1) cost++;
			if (chl == 1) cost+=l;
			if (chr == 1) cost+=r;
			res=min(res,cost);
		}
	}
	return res;
}

int main()
{
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	REP(tst,tests)
	{
		scanf("%d%d",&n,&rootval);
		intn = (n-1)/2;
		REP(i,intn)
			scanf("%d%d",type+i,changable+i);
		for (int i = intn; i < n; i++)
		{
			int t;
			scanf("%d",&t);
			value[i]=t==1;
		}
		for (int i = intn-1; i >= 0; i--)
			if (type[i]==AND)
				value[i]=value[left(i)] && value[right(i)];
			else
				value[i]=value[left(i)] || value[right(i)];
		int res=0;
		if (value[0]!=(rootval==1))
		{
			res=go(0);
		}
		printf("Case #%d: ",tst+1);
		if (res<INF)
			printf("%d",res);
		else
			printf("IMPOSSIBLE");
		printf("\n");
	}
	return 0;
}
