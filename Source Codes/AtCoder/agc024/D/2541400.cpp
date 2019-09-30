#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory.h>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <functional>
#include <queue>

using namespace std;

#define prev prev_______________________
#define next next_______________________
#define hash hash_______________________
#define y1 y1___________________________

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ull = unsigned long long;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#define cerr if (0) cerr
#endif

int n;
vvi g;

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    g.clear();
    g.resize(n);
    forn(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    return 1;
}

void dfs_most(int v, int p, int d, int& best_u, int& best_d) {
    if  (d > best_d) {
        best_d = d;
        best_u = v;
    }
    for (int to : g[v]) {
        if  (to != p) {
            dfs_most(to, v, d + 1, best_u, best_d);
        }
    }
}

pii most_from(int v) {
    int best_u = -1;
    int best_d = -1;
    dfs_most(v, -1, 0, best_u, best_d);
    assert(best_u != -1);
    return mp(best_u, best_d);
}

int dfs_de(int v, int p) {
    int ans = 0;
    for (int to : g[v]) {
        if  (to != p) {
            ans = max(ans, dfs_de(to, v) + 1);
        }
    }
    return ans;
}

int calc_diam() {
    int a = most_from(0).fst;
    return most_from(a).snd;
}

const ull INF = (1ull << 63) + 110;

ull mul(ull a, ull b) {
    if  (a >= INF || b >= INF) {
        return INF;
    }
    ull c = a * b;
    if  (c >= INF || c / a != b || INF / a < b) {
        return INF;
    }
    return c;
}

ull go(const vector<pii>& vers, ull ones) {
    int mx = 0;
    vector<pii> nvers;
    int sum_degs = 0;
    for (const auto& ver : vers) {
        int cur = 0;
        for (int to : g[ver.fst]) {
            if  (to != ver.snd) {
                ++cur; 
                nvers.pb(mp(to, ver.fst));
            }
        }
        mx = max(mx, cur);
        sum_degs += cur;
    }
    if  (mx == 0) {
        assert(nvers.empty());
        return ones + sz(vers);
    }
    ull nxt = mul(ones + sz(vers), mx);
    if  (nxt >= INF) {
        return INF;
    }
    nxt -= sum_degs;
    return go(nvers, nxt);
}

pair<int, ull> solve_fixed() {
    const int diam = calc_diam();

    ull best_cnt = INF;
    forn(v, n) {
        for (int to : g[v]) {
            if  (v > to) {
                continue;
            }
            int dv = dfs_de(v, to);
            int dto = dfs_de(to, v);
            if  (max(dv, dto) * 2 > diam || dv + 1 + dto > diam) {
                continue;
            }
            ull cnt = go(vector<pii>{{v, to}, {to, v}}, 0);
            best_cnt = min(best_cnt, cnt);
            if  (cnt == 2) {
                eprintf("v = %d, to = %d\n", v + 1, to + 1);
            }
        }
    }
    forn(v, n) {
        if  (dfs_de(v, -1) * 2 != diam) {
            continue;
        }
        ull cnt = go(vector<pii>{{v, -1}}, 0);
        best_cnt = min(best_cnt, cnt);
    }
    return mp(diam / 2 + 1, best_cnt);
}

void solve() {
    pair<int, ull> ans(n + 10, 0);

    ans = min(ans, solve_fixed());

    forn(v, n) {
        int nv = n++;
        g[v].pb(nv);
        g.pb({});
        g[nv].pb(v);

        ans = min(ans, solve_fixed());

        --n;
        g.pop_back();
        g[v].pop_back();
    }

    cout << ans.fst << " " << ans.snd << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

#ifdef LOCAL
    #define FNAME "a"
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

    while (read()) {
        solve();

//        break;
    }

    return 0;
}