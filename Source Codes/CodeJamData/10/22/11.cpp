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

int a[64];
int v[64];

int main() {
    #ifdef LOCAL
	freopen("B-large (1).in"  , "r", stdin);
    freopen("B-large (1).out"  , "w", stdout);
    #endif
    int test;
    scanf ("%d", &test);
    FOR (test_num, 1, test + 1) {
        int n, k, b, t;
        cin >> n >> k >> b >> t;
        REP (i, n)
            cin >> a[i];
        REP (i, n)
            cin >> v[i];
        int ans = 0;
        FORD (i, n-1, 0) {
            if (!k) continue;
            if (b - a[i] <= t * v[i])
                --k;
            else
                ans += k;
        }
        if (k)
            printf ("Case #%d: IMPOSSIBLE\n", test_num);
        else
            printf ("Case #%d: %d\n", test_num, ans);
    }
	return 0;
}
