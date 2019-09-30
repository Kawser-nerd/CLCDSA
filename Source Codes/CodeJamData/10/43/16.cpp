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

int a[2048][2048];

queue <PII> q;

void go (int x, int y)
{
    if (x<0 || y<0)
        return;
    if (a[x][y])
        q.push (PII (x, y));
    a[x][y] = 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

    int t;
    cin >> t;
    REP (tt, t)
    {
        cout << "Case #" << (tt+1) << ": ";

        VI x, y;

        memset (a, 0, sizeof (a));
        int n;
        cin >> n;
        VPII b1(n), b2(n);

        REP (i, n)
        {
            cin >> b1[i].X >> b1[i].Y;
            cin >> b2[i].X >> b2[i].Y;
            b2[i].X++;
            b2[i].Y++;

            x.pb (b1[i].X);
            x.pb (b2[i].X);
            y.pb (b1[i].Y);
            y.pb (b2[i].Y);
        }

        UNIQUE(x);
        UNIQUE(y);

        int xx = x.size();
        int yy = y.size();

        REP (i, n)
        {
            int x1 = lower_bound (ALL(x), b1[i].X) - x.begin();
            int x2 = lower_bound (ALL(x), b2[i].X) - x.begin();
            int y1 = lower_bound (ALL(y), b1[i].Y) - y.begin();
            int y2 = lower_bound (ALL(y), b2[i].Y) - y.begin();
            //cout << x1 << " " << y1 << " " << x2 <<  " " << y2 << endl;

            FOR (X, x1, x2)
                a[X][y1] = max(a[X][y1], y2-y1);
        }
        REP (i, xx)
        {
            REP (j, yy)
                if (a[i][j] > 1)
                    a[i][j+1] = max (a[i][j+1], a[i][j]-1);
        }

        int res = 0;
        REP (i, xx)
            REP (j, yy)
                if (a[i][j])
                {

                    go(i, j);
                    int mi = INF;
                    int maxx = 0;
                    int maxy = 0;

                    while (!q.empty())
                    {
                        int X = q.front().X;
                        int Y = q.front().Y;
                        //cout << i << " " << j << " " << X << " " << Y << endl;
                        q.pop();

                        mi = min (mi, x[X] + y[Y]);
                        maxx = max (maxx, x[X+1]-1);
                        maxy = max (maxy, y[Y+1]-1);
                        go (X-1, Y);
                        go (X+1, Y);
                        go (X, Y-1);
                        go (X, Y+1);
                        go (X+1, Y-1);
                        go (X-1, Y+1);
                    }

                    res = max (res, maxx+maxy - mi + 1);
                }
        cout << res << endl;


    }

	return 0;
}
