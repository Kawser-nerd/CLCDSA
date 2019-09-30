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

#define FN "B-large"
#define N 1024000
int c,n,d;
int a[N];

bool check(long double tmm)
{
	long double right = -1.0e15;
	REP(i,n)
	{
		long double x = max(right + d, a[i] - tmm);
		if (x > a[i] + tmm)
			return false;
		right = x;
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
		scanf("%d%d",&c,&d);
		n=0;
		REP(i,c)
		{
			int p,v;
			scanf("%d%d",&p,&v);
			REP(j,v)
				a[n++] = p;
		}
		//n=1000000;
		long double left = 0, right = 1.0e15;
		REP(step,100)
		{
			long double tmm = (left+right) / 2;
			if (check(tmm))
				right = tmm;
			else
				left = tmm;
		}
		LL x = (LL)(left+1.0e-4);
		left -= x;
		int fr;
		if (fabs(left) < 1.0e-4)
		{
			fr = 0;
		}
		else if (fabs(left-0.5) < 1.0e-4)
		{
			fr = 5;
		}
		else
			fprintf(stderr,"BAD!\n");
		printf("Case #%d: %lld.%d\n",test,x,fr);
	}
	return 0;
}