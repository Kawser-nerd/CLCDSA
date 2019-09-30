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

#define FN "E-small-attempt0"

#define N 10
int n;
bool d[1<<N][N];
int a[N][2];

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		scanf("%d",&n);
		CLEAR(d);
		REP(i,n-1)
		{
			REP(j,2) scanf("%d",&a[i][j]),--a[i][j];
		}
		int v = 0;
		int mask = 0;
		int res = 0;
		while (v!=n-1 && !d[mask][v])
		{
			++res;
			d[mask][v] = true;
			int vv = a[v][(mask&(1<<v))?1:0];
			mask ^= 1<<v;
			v=vv;
		}
		/*queue<pair<int,int> > q;
		FILL(d,-1);
		d[0][0] = 0;
		q.push(PII(0,0));
		while (!q.empty()) {
			int mask = q.front().X;
			int v = q.front().Y;
			q.pop();
			
		}*/
		printf("Case #%d: ",test);
		if (v == n-1)
			printf("%d\n",res);
		else
			printf("Infinity\n");
	}
	return 0;
}