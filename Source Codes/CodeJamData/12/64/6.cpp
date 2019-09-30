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

#define FN "D-small-attempt0"
#define N 5555
int n,m;
int ax[N],ay[N];

set<PII> s;
LL res;
int mxid[4];

void go(int x, int y, int left)
{
	//s.insert(PII(x,y));
	res = max(x*(LL)x+y*(LL)y,res);
	if (left == 0) return;
	int sf = mxid[left%4];
	REP(i,sf+1)
	//REP(i,n)
	{
		int xx = ax[i]-ay[i] + y;
		int yy = ax[i]+ay[i] - x;
		mxid[left%4] = i;
		go(xx,yy,left-1);
	}
	mxid[left%4] = sf;
}

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	/*PII x(1,0), y(0,1);
	REP(step,10)
	{
		printf("%d*x + %d*y \t %d*x + %d*y\n",x.first,x.second,y.first,y.second);
		PII xx(x.first+y.first,);
	}*/

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"%d\n",test);
		scanf("%d%d",&n,&m);
		REP(i,n)
			scanf("%d%d",ax+i,ay+i);
		res = 0;
		REP(i,4) mxid[i] = n-1;
		go(0,0,m);
		printf("Case #%d: %.12lf\n",test,sqrt((double)res));
	}
	return 0;
}