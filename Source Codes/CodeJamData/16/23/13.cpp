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
 * Dinic法による最大流
 *
 * ほとんど蟻本そのまま
 * template引数のint Vは頂点数
 */
template<int V>
struct MaxFlow {
    using T = int; /// 辺の重みの型
    const T INF = 1<<28;
    struct Edge {
        int to, rev;
        T cap;
    };
    vector<Edge> g[V];
    int level[V];
    int iter[V];
    /// 初期化
    void init() {
        for (int i = 0; i < V; i++) {
            g[i].clear();
        }
    }
    /// 有向辺の追加
    void add(int from, int to, T cap) {
        g[from].push_back(Edge{to, (int)g[to].size(), cap});
        g[to].push_back(Edge{from, (int)g[from].size()-1, 0});
    }
    /// 無向辺の追加
    void add_multi(int from, int to, T cap) {
        g[from].push_back(Edge{to, (int)g[to].size(), cap});
        g[to].push_back(Edge{from, (int)g[from].size()-1, cap});
    }

    void bfs(int s) {
        fill_n(level, V, -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (Edge e: g[v]) {
                if (e.cap <= 0) continue;
                if (level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    T dfs(int v, int t, T f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < (int)g[v].size(); i++) {
            Edge &e = g[v][i];
            if (e.cap <= 0) continue;
            if (level[v] < level[e.to]) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d <= 0) continue;
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }

    // sからtへの最大流を返す
    T exec(int s, int t) {
        T flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill_n(iter, V, 0);
            T f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
    }
};

const int MN = 1010;

string l[MN], r[MN];

int solve() {
    MaxFlow<MN*2+2> mf;
    int n;
    cin >> n;
    int c1 = 0, c2 = 0;
    map<string, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        if (mp1.count(l[i]) == 0) {
            mp1[l[i]] = c1++;
        }
        if (mp2.count(r[i]) == 0) {
            mp2[r[i]] = c2++;
        }
    }
    mf.init();
    for (int i = 0; i < n; i++) {
        mf.add(mp1[l[i]], MN+mp2[r[i]], 1);
    }
    int sv = MN*2, tv = MN*2+1;
    for (int i = 0; i < c1; i++) {
        mf.add(sv, i, 1);
    }
    for (int i = 0; i < c2; i++) {
        mf.add(MN+i, tv, 1);
    }
    return n - (c1+c2 - mf.exec(sv, tv));
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: %d\n", t, solve());
    }
    return 0;
}