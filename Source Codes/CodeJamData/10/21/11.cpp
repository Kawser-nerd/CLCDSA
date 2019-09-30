#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;

int main() {
    #ifdef LOCAL
	freopen( "A-large (1).in" , "r", stdin);
    freopen( "A-large (1).out" , "w", stdout);
    #endif
    int test;
    scanf ("%d", &test);
    FOR (test_num, 1, test + 1) {
        int n, m;
        vector <map <string, int> > next;
        cin >> n >> m;
        int res = 0;
        next.pb (map <string, int> ());
        REP (i, n+m) {
            string s;
            cin >> s;
            REP (j, SZ (s)) if (s[j] == '/') s[j] = ' ';
            istringstream str (s);
            string g;
            int cur = 0;
            while (str >> g) {
                if (!next[cur].count (g)) {
                    next[cur][g] = SZ (next);
                    next.pb (map <string, int> ());
                    if (i >= n) ++res;
                }
                cur = next[cur][g];
            }
        }
        printf ("Case #%d: %d\n", test_num, res);
    }
	return 0;
}
