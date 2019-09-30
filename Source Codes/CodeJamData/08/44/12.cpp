#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (c).size()
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

int c[16][16];
int r[1<<16][16];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int tt;
	cin >> tt;

	REP (t, tt)
	{
		cout << "Case #" << (t+1) << ": ";

		int k;
		string s;
		cin >> k >> s;
		memset (c, 0, sizeof (c));

		REP (i, s.size ()/k)
		{
			REP (x, k)
				REP (y, k)
					if (s[i*k+x]!=s[i*k+y])
						c[x][y] ++;
		}

		int res = INF;

		REP (x, k)
			REP (y, k)
			if (x!=y)
			{
				int rr = 0;

				REP (i, s.size ()/k-1)
					if (s[i*k+y]!=s[i*k+k+x])
						rr++;

				REP (i, 1<<k)
					REP (j, 16)
						r[i][j] = INF;

				r[(1<<x)|(1<<y)][x] = rr;

				REP (i, 1<<k)
					REP (j, k)
						if (r[i][j]<INF)
							REP (l, 16)
								if (!(i & (1<<l)))
									r[i|(1<<l)][l]<?=r[i][j]+c[j][l];

				REP (j, k)
					res<?=r[(1<<k)-1][j] + c[y][j];
			}

		cout << res+1 << endl;
	}

	return 0;
}
