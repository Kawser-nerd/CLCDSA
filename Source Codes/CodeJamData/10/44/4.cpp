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

typedef long double cfloat;

const cfloat pi = 2*acosl(0);

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

    int t;
    cin >> t;
    REP (tt, t)
    {
        printf ("Case #%d:", tt+1);

        int n, m;
        cin >> n >> m;

        cfloat x1, y1;
        cfloat x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        vector <cfloat> r;

        REP (ttt, m)
        {
            cfloat xxx, yyy;
            cin >> xxx >> yyy;
            cfloat r1 = hypotl(x1- xxx, y1-yyy);
            cfloat r2 = hypotl(x2- xxx, y2-yyy);

            cfloat d = hypotl (x1-x2, y1-y2);

            cfloat res = 0;

            if (r1>r2)
            {
                swap (r1, r2);
                swap (x1,x2);
                swap (y1,y2);
            }

            if (r1+r2 <= d)
            {
                r.pb (0);
                continue;
            }
            if (r1+d <=r2)
            {
                r.pb (pi*r1*r1);
                continue;
            }

            cfloat s = r1*r1*acosl((d*d+r1*r1 - r2*r2)/2/d/r1)+
                       r2*r2*acosl((d*d+r2*r2 - r1*r1)/2/d/r2)-
                    0.5*sqrtl((-d+r1+r2)*(d+r1-r2)*(d-r1+r2)*(d+r1+r2));
            r.pb (s);
        }

        REP (i, r.size ())
        {
            printf (" %.7lf", (double)r[i]);
        }
        printf ("\n");

    }

	return 0;
}
