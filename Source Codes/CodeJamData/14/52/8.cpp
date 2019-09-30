// Rain Dreamer MODEL
// Create @ 22:49 06-14 2014
// Comment - 

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Self Template Code BGEIN

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define all(x) (x).begin(), (x).end()
#define RD(x) freopen (x, "r", stdin)
#define WT(x) freopen (x, "w", stdout)
#define clz(x) memset (x, 0, sizeof(x))
#define cln(x) memset (x, -1, sizeof(x))
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;

int sgn(double x) { return (x > 1e-8) - (x < -1e-8); }
int count_bit(int x) { return x == 0? 0 : count_bit(x >> 1) + (x & 1); }

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

const int MAXN = 100 + 10;

int p, q, n, a[MAXN], g[MAXN];
int dp[MAXN][MAXN * 10];

int solve() {
    cln (dp);
    dp[0][1] = 0;
    int max_left_tm = 1;
    rep (i, n) {
        int left = a[i] % q;
        if (left == 0) left = q;
        int need_tm = (left + p - 1) / p;
        int tower_need_tm = (a[i] + q - 1) / q;
        int tower_need_tm_non_lt = (a[i] - left) / q;
        int next_max_left_tm = max_left_tm;
        repf (j, 0, max_left_tm) {
            if (dp[i][j] == -1) continue;
            // give up
            ckmax (dp[i + 1][j + tower_need_tm], dp[i][j]);
            ckmax (next_max_left_tm, j + tower_need_tm);
            // get
            int free_tm = j + tower_need_tm_non_lt;
            if (free_tm >= need_tm) {
                ckmax (dp[i + 1][free_tm - need_tm], dp[i][j] + g[i]);
                ckmax (next_max_left_tm, free_tm - need_tm);
            }
        }
        max_left_tm = next_max_left_tm;
    }
    int ans = 0;
    repf (j, 0, max_left_tm) {
        ckmax (ans, dp[n][j]);
    }
    return ans;
}

int main() {
    WT ("B.out");
    
    repcase {
        scanf ("%d%d%d", &p, &q, &n);
        rep (i, n) scanf ("%d%d", &a[i], &g[i]);
        printf ("Case #%d: %d\n", Case++, solve());
    }
    return 0;
}

