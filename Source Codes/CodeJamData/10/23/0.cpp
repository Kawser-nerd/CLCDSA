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

#define mod 100003
#define MAX 512

long long r[MAX][MAX];
long long cnk[MAX][MAX];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

    memset (r, 0, sizeof (r));

    REP (i, MAX)
        REP (j, MAX)
        {
            if (i<j)
                cnk[i][j] =0;
            else if (i==j || j==0 )
                cnk[i][j] = 1;
            else
                cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1])%mod;
        }

    FOR (i, 2, MAX)
        r[i][1] = 1;

    FOR (i, 2, MAX)
        FOR (j, 2, i)
        {
            FOR (k, 1, j)
            {
                r[i][j] += r[j][k]*cnk[i-j-1][j-k-1];
            }
            r[i][j]%= mod;
        }

    int t;
    cin >> t;
    REP (tt, t)
    {
        cout << "Case #" << (tt+1) << ": ";

        int n;
        cin >> n;
        long long res = 0;
        FOR (j, 1, n)
            res += r[n][j];
        res %= mod;
        cout << res << endl;
    }

	return 0;
}
