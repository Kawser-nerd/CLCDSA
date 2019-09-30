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

#define FN "B-large"
#define N 11000
int E,R,n;
int a[N],b[N],need[N];
PII order[N];
LL res = 0;

void rec(int i, int e, LL cur)
{
	if (i==n)
	{
		res=max(res,cur);
		return;
	}
	FOR(j,0,e)
		rec(i+1,min(E,e-j+R),cur+j*a[i]);
}

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		printf("Case #%d: ",test);
		scanf("%d%d%d",&E,&R,&n);
		REP(i,n)
		{
			scanf("%d",&a[i]);
		}
		/*E=10000000;
		R=1;
		n=10000;
		REP(i,n) a[i]=E-i;*/

		REP(i,n) {
			order[i]=PII(a[i],i);
			b[i]=E;
		}
		sort(order,order+n);
		reverse(order,order+n);
		res = 0;
		int last = -1;
		FILL(need,-1);
		REP(iii,n)
		{
			int i = order[iii].second;
			int take = b[i];
			need[i] = b[i];
			int lev = 0;
			for (int j = i+1; j < n; ++j)
			{
				lev = min(lev+R,E);
				if (lev < need[j])
				{
					take -= need[j]-lev;
					break;
				}
				if (lev == E)
					break;
			}
			b[i]-=take;
			lev = b[i];
			for (int j = i+1; j < n; ++j)
			{
				lev = min(lev+R,E);
				if (lev == E) break;
				if (need[j] != -1) break;
				b[j] = lev; 
			}
			res += a[i]*(LL)take;
		}
		//res = 0;
		//rec(0,E,0);
		printf("%lld\n",res);
	}
	return 0;
}