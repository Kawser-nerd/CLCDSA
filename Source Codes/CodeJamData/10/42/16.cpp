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
#define INF 1000000000000000000LL
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

    int t;
    cin >> t;
    REP (tt, t)
    {
        cout << "Case #" << (tt+1) << ": ";

        int p;
        cin >> p;

        int n = 1<<p;
        VI a(n);
        REP (i, n)
            cin >> a[i];

        queue <vector <long long> > q;

        REP (i, n)
        {
            vector <long long> b(p+1);
            FOR (j, a[i]+1, p+1)
                b[j] = INF;
            q.push(b);
        }

        REP (ii, n-1)
        {

            vector <long long> b1, b2;
            b1 = q.front();
            q.pop();
            b2 = q.front();
            q.pop();
            vector <long long> b(p+1, INF);
            long long c;
            cin >> c;
            //cout << c << endl;
            REP (i, p+1)
            {
                b[i] = min (b[i], b1[i]+b2[i]+c);
                if (i<p)
                {
                    b[i] = min (b[i], b1[i+1]+b2[i+1]);
                    b[i] = min (b[i], b[i+1]);
                }
            }
            q.push(b);
        }

        cout << q.front()[0] << endl;
    }

	return 0;
}
