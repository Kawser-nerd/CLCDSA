#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

int dp[101][101][101];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(a1, 101) forn(a2, 101) forn(a3, 101) {
        int m = (a1 + 2 * a2 + 3 * a3) % 4;
        if (a1) uax(dp[a1][a2][a3], dp[a1 - 1][a2][a3] + int(m == 0));
        if (a2) uax(dp[a1][a2][a3], dp[a1][a2 - 1][a3] + int(m == 0));
        if (a3) uax(dp[a1][a2][a3], dp[a1][a2][a3 - 1] + int(m == 0));
    }

    int T;
    cin >> T;
    for1(tc, T) {
        int n, p;
        cin >> n >> p;
        vi a(p);
        int s = 0;
        forn(i, n) {
            int x;
            cin >> x;
            x %= p;
            ++a[x];
            s += x; s %= p;
//            cerr << s << '\n';
        }

        int ans = 1 - int(s == 0);
        if (p == 2) {
            ans += a[0] + a[1] / 2;
        } else if (p == 3) {
            ans += a[0];
            int res = 0;
            forn(t, a[1] + 1) {
                uax(res, min(t, a[2]) + (a[1] - t) / 3 + max(0, a[2] - t) / 3);
            }
//            cerr << s << ' ' << ans << ' ' << res << '\n';
            ans += res;
        } else if (p == 4) {
            ans += a[0] + dp[a[1]][a[2]][a[3]];
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
