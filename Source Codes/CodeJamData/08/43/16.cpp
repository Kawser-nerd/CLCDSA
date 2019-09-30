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
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define NAME "C-large"
#define N 1024
int n;
int coords[N][3];
int p[N];

bool solve(double d)
{
	double minv[4],maxv[4];
	REP(i,4)
	{
		minv[i]=-1.0e20;
		maxv[i]=+1.0e20;
	}
	REP(i,n)
	{
		double maxd = d*p[i];
		REP(j,4)
		{
			double mysum=coords[i][2];
			REP(k,2)
				if ((j & (1<<k)) != 0)
					mysum+=coords[i][k];
				else
					mysum-=coords[i][k];
			minv[j]=max(minv[j],mysum-maxd);
			maxv[j]=min(maxv[j],mysum+maxd);
		}
	}
	REP(j,4)
		if (minv[j]>maxv[j])
			return false;
	return true;
}

int main()
{
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	REP(tst,tests)
	{
		scanf("%d",&n);
		REP(i,n)
		{
			REP(j,3)
				scanf("%d",&coords[i][j]);
			scanf("%d",&p[i]);
		}
		double l=0,r=5.0e+07;
		while (fabs(l-r)>1.0e-8)
		{
			double dist=(l+r)/2;
			if (solve(dist))
				r=dist;
			else
				l=dist;
		}
		printf("Case #%d: %.8lf\n",tst+1,(l+r)/2);
	}
	return 0;
}
