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


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int tt;
	cin >> tt;
	REP (t, tt)
	{
		cout << "Case #" << t+1 << ": ";

		int n, m, a;

		cin >> n >> m >> a;

		FOR (x1, -n, n+1)
			FOR (y1, -m, m+1)
				FOR (x2, -n, n+1)
					FOR (y2, -m, m+1)
					{
						if (max (x1,x2)-min(x1,x2)>n)
							continue;
						if (max (y1,y2)-min(y1,y2)>m)
							continue;

						if (abs (x1*y2-x2*y1) == a)
						{
							int x = 0;
							int y = 0;
							x>?=-x1; x>?=-x2;
							y>?=-y1; y>?=-y2;

							cout << x << " " << y << " " << x1 + x << " " << y1 + y << " " << x2 + x << " " << y2 + y << endl;
							goto next;
						}
					}

		cout << "IMPOSSIBLE" << endl;
		next:;
	}

	return 0;
}
