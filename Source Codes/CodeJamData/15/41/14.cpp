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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string dn = "v>^<";

int N, M;

bool ok(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    int T;
    cin >> T;
    for1(t, T) {
        cin >> N >> M;
        vector<string> f(N);
        forn(i, N) cin >> f[i];
        int ans = 0;
        forn(i, N) forn(j, M) {
            if (f[i][j] == '.') continue;
            int d = 0;
            while (f[i][j] != dn[d]) ++d;
            int x, y;
            for (x = i + dx[d], y = j + dy[d]; ok(x, y) && f[x][y] == '.'; x += dx[d], y += dy[d]) {}
            if (ok(x, y)) continue;
            bool ch = false;
            forn(k, N) ch |= i != k && f[k][j] != '.';
            forn(k, M) ch |= j != k && f[i][k] != '.';
            if (!ch) ans = 1e9;
            else ++ans;
        }
        printf("Case #%d: ", t);
        if (ans > 1e8) printf("impossible\n");
        else printf("%d\n", ans);
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
