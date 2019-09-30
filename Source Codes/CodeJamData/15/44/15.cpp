#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

int N, M;
int f[20][20], lft[20][20], same[20][20];

bool frnd(int x, int y, int t) {
    --lft[x][y];
    if (f[x][y] == t) ++same[x][y];
    if (same[x][y] > f[x][y]) return false;
    if (f[x][y] > same[x][y] + lft[x][y]) return false;
    return true;
}

void unfrnd(int x, int y, int t) {
    ++lft[x][y];
    if (f[x][y] == t) --same[x][y];
}

int ans = 0;   

void rec(int x, int y) {
    if (x == N) {
        forn(i, N) {
            forn(j, M) cout << f[i][j];
            cout << '\n';
        }
        cout << '\n';
        ++ans;
        return;
    }
    if (y == M) {
        rec(x + 1, 0);
        return;
    }
    for1(t, 3) {
        f[x][y] = t;
        bool ok = true;
        if (x > 0) ok &= frnd(x - 1, y, t), ok &= frnd(x, y, f[x - 1][y]);
        if (y > 0) ok &= frnd(x, y - 1, t), ok &= frnd(x, y, f[x][y - 1]);
        if (y + 1 == M) ok &= frnd(x, 0, t), ok &= frnd(x, y, f[x][0]);
        if (ok) rec(x, y + 1);
        if (x > 0) unfrnd(x - 1, y, t), unfrnd(x, y, f[x - 1][y]);
        if (y > 0) unfrnd(x, y - 1, t), unfrnd(x, y, f[x][y - 1]);
        if (y + 1 == M) unfrnd(x, 0, t), unfrnd(x, y, f[x][0]);
    }
}

i64 dp[110][3][13];
const i64 P = 1000000000 + 7;

void add(i64 &x, i64 y) {
    x += y; x %= P;
}

int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) y *= x, y %= P;
        x *= x, x %= P;
        d /= 2;
    }
    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
/*#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif*/

    int T;
    cin >> T;
    for1(t, T) {
        cin >> N >> M;
        forn(i, N + 1) forn(j, 3) forn(k, 13) dp[i][j][k] = 0;
        dp[0][0][1] = 1;
        forn(i, N) forn(j, 3) forn(k, 13) {
            if (j != 1) add(dp[i + 2][1][k], dp[i][j][k]);
            if (j != 2) {
                add(dp[i + 1][2][k], dp[i][j][k]);
                if (M % 6 == 0) add(dp[i + 2][2][lcm(k, 6)], 6 * dp[i][j][k]);
                if (M % 4 == 0) add(dp[i + 3][2][lcm(k, 4)], 4 * dp[i][j][k]);
                if (M % 3 == 0) add(dp[i + 2][2][lcm(k, 3)], 3 * dp[i][j][k]);
            }
        }
        i64 ans = 0;
        forn(j, 3) forn(k, 13) ans += dp[N][j][k] * deg(k, -1) % P;
        ans %= P;
        cout << "Case #" << t << ": " << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
