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

const int maxn = 51, maxk = maxn * maxn;
int n, m;
string f[maxn];
int hit[maxn][maxn][2];
vector<pii> beams;
vi e[maxk], re[maxk];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool ok(int x, int y) {
    return min(x, y) >= 0 && min(n - x, m - y) > 0;
}

bool dfs(int x, int y, int d, int add) {
    if (!ok(x, y) || f[x][y] == '#') return true;
    if (f[x][y] == '-' || f[x][y] == '|') return false;
    int dd = d;
    if (add != -1 && f[x][y] == '.') hit[x][y][d & 1] = add;
    if (f[x][y] == '/') dd = d ^ 3;
    if (f[x][y] == '\\') dd = d ^ 1;
    return dfs(x + dx[dd], y + dy[dd], dd, add);
}

void addEdge(int x, int y) {
    e[x].pb(y); re[y].pb(x);
    e[y ^ 1].pb(x ^ 1); re[x ^ 1].pb(y ^ 1);
}

vi ord;
int vis[maxk], comp[maxk];

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    for (int u: e[v]) dfs(u);
    ord.pb(v);
}

void dfs_re(int v, int cc) {
    if (vis[v]) return;
    comp[v] = cc;
    vis[v] = 1;
    for (int u: re[v]) dfs_re(u, cc);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    for1(tc, T) {
        cin >> n >> m;
        forn(i, n) forn(j, m) forn(k, 2) hit[i][j][k] = -1;
        forn(i, n) cin >> f[i];
        forn(i, n) forn(j, m) {
            if (f[i][j] == '-' || f[i][j] == '|') beams.pb({i, j});
        }

        int K = beams.size();
        forn(i, K) forn(d, 2) {
            int x = beams[i].fi, y = beams[i].se;
            bool ok = true;
            forn(j, 2) {
                int dd = d | (j << 1);
                ok &= dfs(x + dx[dd], y + dy[dd], dd, -1);
            }
            if (ok) {
                forn(j, 2) {
                    int dd = d | (j << 1);
                    ok &= dfs(x + dx[dd], y + dy[dd], dd, 2 * i + d);
                }
            } else {
                addEdge(2 * i + d, 2 * i + (d ^ 1));
            }
        }

        bool ok = true;
        forn(i, n) forn(j, m) {
            if (f[i][j] != '.') continue;
            int z0 = hit[i][j][0], z1 = hit[i][j][1];
            if (z0 == -1 && z1 == -1) ok = false;
            else if (z0 == -1) addEdge(z1 ^ 1, z1);
            else if (z1 == -1) addEdge(z0 ^ 1, z0);
            else {
                addEdge(z0 ^ 1, z1);
                addEdge(z1 ^ 1, z0);
            }
        }

        ord.clear();
        forn(i, 2 * K) vis[i] = 0;
        forn(i, 2 * K) dfs(i);
        reverse(all(ord));
        int cc = 0;
        forn(i, 2 * K) vis[i] = 0;
        for (int v: ord) dfs_re(v, cc++);

        forn(i, K) {
            ok &= comp[2 * i] != comp[2 * i + 1];
        }

        cout << "Case #" << tc << ": ";
        if (!ok) cout << "IMPOSSIBLE\n";
        else {
            forn(i, K) {
                int x = beams[i].fi, y = beams[i].se;
                f[x][y] = "|-"[comp[2 * i] < comp[2 * i + 1]];
            }
            cout << "POSSIBLE\n";
            forn(i, n) cout << f[i] << '\n';
        }

        beams.clear();
        forn(i, 2 * K) e[i].clear(), re[i].clear();
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
