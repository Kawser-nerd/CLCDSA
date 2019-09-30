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

#define FN "a"

#define N 128
#define K 1024
int n;
int x[N],y[N],st[N];
vector<pair<int,int> > ev;
int d[N][K],mxx[N][K];

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		scanf("%d",&n);
		ev.clear();
		CLEAR(d);
		CLEAR(mxx);
		REP(i,n) {
			scanf("%d%d%d",x+i,y+i,st+i);
			FOR(dd,0,1000) ev.pb(make_pair(st[i]+dd,i));
		}
		SORT(ev);
		int res = 0;
		REP(ii,SZ(ev))
		{
			int id = ev[ii].second;
			int tmm = ev[ii].first;
			int &cur = d[id][tmm-st[id]];
			if (max(abs(x[id]),abs(y[id]))*100 <= tmm)
				cur = max(cur, 1);
			REP(j,n) if (j != id) {
				int xtm = tmm - max(max(abs(x[id]-x[j]),abs(y[id]-y[j]))*100,750);
				if (xtm < st[j]) continue;
				cur = max(cur,mxx[j][min(1000,xtm-st[j])]+1);
			}
			if (tmm == st[id])
				mxx[id][tmm-st[id]] = cur;
			else
				mxx[id][tmm-st[id]] = max(mxx[id][tmm-st[id]-1], cur);
			res = max(res,cur);
		}
		printf("Case #%d: %d\n",test,res);
	}
	return 0;
}