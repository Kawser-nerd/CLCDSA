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

#define FN "A-large"
#define N 128
int n;
int a[N][N];
double wp[N],owp[N],oowp[N];

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		scanf("%d",&n);
		REP(i,n) REP(j,n)
		{
			char c;
			do c = getc(stdin);
			while (c!='0'&&c!='1'&&c!='.');
			if (c=='0')
				a[i][j] = 0;
			else if (c=='1')
				a[i][j] = 1;
			else
				a[i][j] = -1;
		}
		REP(i,n)
		{
			int q=0,w=0;
			REP(j,n)
				if (a[i][j] != -1)
				{
					q+=a[i][j];
					w++;
				}
			wp[i] = q/(double)w;
		}
		REP(ii,n)
		{
			owp[ii] = 0;
			int cnt = 0;
			REP(i,n) if (a[ii][i] != -1)
			{
				int q=0,w=0;
				REP(j,n)
					if (a[i][j] != -1 && j != ii)
					{
						q+=a[i][j];
						w++;
					}
				owp[ii] += q/(double)w;
				cnt++;
			}
			owp[ii] /= cnt;
		}
		REP(i,n)
		{
			oowp[i] = 0;
			int cnt = 0;
			REP(j,n) if (a[i][j] != -1)
			{
				oowp[i] += owp[j];
				cnt++;
			}
			oowp[i] /= cnt;
		}
		printf("Case #%d:\n",test);
		REP(i,n)
			printf("%.12lf\n", 0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i]);
	}
	return 0;
}