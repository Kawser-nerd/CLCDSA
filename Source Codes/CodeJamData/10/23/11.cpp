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

const int mod = 100003;

int d[512][512];
int cnk[512][512];
int ans[512];

int main() {
    #ifdef LOCAL
	freopen("C-large (1).in"  , "r", stdin);
    freopen("C-large (1).out"  , "w", stdout);
    #endif
    int test;
    
    REP (i, 512) {
        cnk[i][0] = cnk[i][i] = 1;
        FOR (j, 1, i)
            cnk[i][j] = (cnk[i-1][j-1] + cnk[i-1][j]) % mod;
    }
    FOR (i, 2, 512) {
        d[i][1] = 1;
        FOR (j, 2, i) {
            REP (k, j) if (i - j - 1 >= j-k-1)
                d[i][j] = (d[i][j] + (long long) d[j][k] * cnk[i-j-1][j-k-1]) % mod;
        }            
    }
    REP (i, 512) {
        REP (j, i) {
            ans[i] += d[i][j];
            ans[i] %= mod;
        }
    }
    scanf ("%d", &test);    
    FOR (test_num, 1, test + 1) {
        int n;
        cin >> n;

        printf ("Case #%d: %d\n", test_num, ans[n]);
    }
	return 0;
}
