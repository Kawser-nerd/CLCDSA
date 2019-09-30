#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

/**
 * Dijkstra????????????
 *
 * template???int V????
 */
template<int V>
struct Dijkstra {
    using T = int; /// ??????
    const int INF = 1<<28;
    typedef pair<T, int> P;
    vector<P> g[V];
    /// ?????
    void init() {
        for (int i = 0; i < V; i++) {
            g[i].clear();
        }
    }
    /// ????
    void add(int from, int to, T dist) {
        g[from].push_back(P(dist, to));
    }
    T res[V]; /// exec??????????????? 
    void exec(int s) {
        fill_n(res, V, INF);
        priority_queue<P, vector<P>, greater<P>> q;
        q.push(P(0, s));
        res[s] = 0;
        while (!q.empty()) {
            P p = q.top(); q.pop();
            if (res[p.second] < p.first) continue;
            for (P e: g[p.second]) {
                if (p.first+e.first < res[e.second]) {
                    res[e.second] = p.first+e.first;
                    q.push(P(p.first+e.first, e.second));
                }
            }
        }
        return;
    }
};

const int MN = 10100;
const int MM = 100100;
const int B = 200;
using P = pair<int, int>;
int n, m;
int a[MM], b[MM], c[MM];
vector<P> g[MN];
int minuse[MN];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", c+i, a+i, b+i);
        g[a[i]].push_back(P(b[i], c[i]));
        g[b[i]].push_back(P(a[i], c[i]));
    }

    Dijkstra<MN> djk;
    djk.init();
    for (int i = 0; i < m; i++) {
        if (c[i] == 0) {
            djk.add(a[i], b[i], 0);
            djk.add(b[i], a[i], 0);
        } else {
            djk.add(a[i], b[i], 1);
            djk.add(b[i], a[i], 1);
        }
    }
    djk.exec(0);
    for (int i = 0; i < n; i++) {
        minuse[i] = djk.res[i];
    }

    ll ans[MN];
    fill_n(ans, MN, 1LL<<55);
    using Q = tuple<ll, int, int>;
    priority_queue<Q, vector<Q>, greater<Q>> q;
    ll used[MN][B];
    for (int i = 0; i < MN; i++) {
        for (int j = 0; j < B; j++) {
            used[i][j] = 1LL<<55;
        }
    }
    q.push(Q(0, 0, 0));
    while (!q.empty()) {
        ll d; int p, us;
        tie(d, p, us) = q.top(); q.pop();
        if (us >= minuse[p]+B) continue;
        if (used[p][us-minuse[p]] < d) continue;
        ans[p] = min(ans[p], d);
        for (P ed: g[p]) {
            if (ed.second == 0) {
                if (used[ed.first][us-minuse[ed.first]] <= d+1) continue;
                used[ed.first][us-minuse[ed.first]] = d+1;
                q.push(Q(d+1, ed.first, us));
            } else {
                if (us+1-minuse[ed.first] >= B) continue;
                if (used[ed.first][us+1-minuse[ed.first]] <= d+us+1) continue;
                used[ed.first][us+1-minuse[ed.first]] = d+us+1;
                q.push(Q(d+us+1, ed.first, us+1));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}