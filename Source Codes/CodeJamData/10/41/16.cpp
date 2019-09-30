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

int a[256][256];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

    int t;
    cin >> t;
    REP (tt, t)
    {
        cout << "Case #" << (tt+1) << ": ";

        int n;
        cin >> n;

        memset (a, 0, sizeof (a));

        FOR (x, -n+1, n)
        {
            for (int y = abs(x)-n+1; y<=n-1-abs(x); y+=2)
            {
                //cout << x << " " << y << endl;
                cin >> a[x+128][y+128];
                a[x+128][y+128] ++;
            }
        }

        int r = n*4;

        FOR (i, 128-60, 128+60)
            FOR (j, 128-60, 128+60)
            {
                bool ok = true;
                int d = 0;
                FOR (x, -60+128, 60+128)
                    FOR (y, -60+128, 60+128)
                        if (a[x][y])
                        {
                            d = max (d, abs(x-i) + abs (y-j));
                            if (a[x][j*2-y] && a[x][j*2-y] != a[x][y])
                                ok = false;
                            if (a[i*2-x][y] && a[i*2-x][y] != a[x][y])
                                ok = false;
                        }
                if (ok)
                    r = min (r, d+1);
            }

        cout << (r*r - n*n) << endl;

    }

	return 0;
}
