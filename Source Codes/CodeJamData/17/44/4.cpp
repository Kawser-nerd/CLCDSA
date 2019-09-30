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

const int maxn = 110;
string f[maxn];
vector<pii> solds, turs;
vector<pii> bord;
vi cont[maxn][maxn];
int sal[maxn], tal[maxn];
int dist[maxn][maxn];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int c, r, m;

bool ok(int x, int y) {
    return min(x, y) >= 0 && min(r - x, c - y) > 0;
}

void bfs(int x, int y, set<int> &can_kill, bool unl) {
    forn(i, r) forn(j, c) dist[i][j] = 1e9;
    dist[x][y] = 0;
    vector<pii> q;
    q.pb({x, y});
    forn(cur, q.size()) {
        int x = q[cur].fi, y = q[cur].se;
        if (dist[x][y] > m) break;
        bool st = false;
        for (int t: cont[x][y]) st |= tal[t];
        if (st) {
            for (int t: cont[x][y]) if (tal[t]) can_kill.insert(t);
            if (!unl) continue;
        }
        forn(d, 4) {
            int xx = x + dx[d], yy = y + dy[d];
            if (!ok(xx, yy) || f[xx][yy] == '#' || dist[xx][yy] < 1e8) continue;
            dist[xx][yy] = dist[x][y] + 1;
            q.pb({xx, yy});
        }
    }
    return;
}

vi e[maxn];
int vis[maxn], match[maxn], med[maxn];

bool dfs(int v) {
    if (vis[v] || !sal[v]) return false;
    vis[v] = 1;
    for (int u: e[v]) {
        if (!tal[u]) continue;
        if (match[u] == -1 || dfs(match[u])) {
            match[u] = v;
            return true;
        }
    }
    return false;
}

int kuhn() {
    forn(i, solds.size()) med[i] = 0;
    forn(i, turs.size()) match[i] = -1;
    int ans = 0;
    forn(i, solds.size()) {
        if (!sal[i]) continue;
        for (int t: e[i]) {
            if (!tal[t] || match[t] != -1) continue;
            match[t] = i;
            med[i] = 1;
            ++ans;
            break;
        }
    }

    forn(i, solds.size()) {
        if (!sal[i] || med[i]) continue;
        forn(j, solds.size()) vis[j] = 0;
        ans += int(dfs(i));
    }
    return ans;
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
        cerr << tc << '\n';
        cin >> c >> r >> m;
        forn(i, r) {
            cin >> f[i];
            forn(j, c) {
                if (f[i][j] == 'S') solds.pb({i, j});
                if (f[i][j] == 'T') turs.pb({i, j});
            }
        }

        forn(i, solds.size()) sal[i] = 1;
        forn(i, turs.size()) tal[i] = 1;

        forn(k, turs.size()) {
            int x = turs[k].fi, y = turs[k].se;
            forn(d, 4) {
                for (int xx = x + dx[d], yy = y + dy[d]; ok(xx, yy) && f[xx][yy] != '#'; xx += dx[d], yy += dy[d]) cont[xx][yy].pb(k);
            }
        }

        forn(i, solds.size()) {
            set<int> can_kill;
            bfs(solds[i].fi, solds[i].se, can_kill, true);
            for (int t: can_kill) e[i].pb(t);
        }

        int ans = kuhn();
        cout << "Case #" << tc << ": " << ans << '\n';
        while (ans) {
            forn(i, solds.size()) {
                if (!sal[i]) continue;
                set<int> ck;
                bfs(solds[i].fi, solds[i].se, ck, false);
                for (int t: ck) {
                    sal[i] = tal[t] = 0;
                    if (kuhn() == ans - 1) {
                        cout << i + 1 << ' ' << t + 1 << '\n';
                        --ans;
                        break;
                    }
                    sal[i] = tal[t] = 1;
                }
            }
        }

        forn(i, solds.size()) e[i].clear();
        solds.clear();
        turs.clear();
        forn(i, r) forn(j, c) cont[i][j].clear();
        bord.clear();
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
