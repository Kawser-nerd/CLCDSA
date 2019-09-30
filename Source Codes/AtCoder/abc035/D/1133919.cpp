#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

constexpr ll INF = 1e18;

struct edge {
    ll to, cost;
};

using edges = vector<edge>;
using graph = vector<edges>;

vector<ll> dijkstra(graph& g, int s) {
    vector<ll> d(g.size(), INF);
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P{0, s});
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) {
            continue;
        }
        for(auto& e : g[v]) {
            int u = e.to;
            if(d[u] > d[v] + e.cost) {
                d[u] = d[v] + e.cost;
                que.push(P{d[u], u});
            }
        }
    }
    return d;
}

int main() {
    ll N, M, T;
    cin >> N >> M >> T;
    vector<ll> A(N);
    for(int i=0; i<N; ++i) {
        cin >> A[i];
    }
    graph g(N), g2(N);
    for(int i=0; i<M; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back((edge){b, c});
        g2[b].push_back((edge){a, c});
    }
    auto d1 = dijkstra(g, 0);
    auto d2 = dijkstra(g2, 0);
    ll res = 0;
    for(int i=0; i<N; ++i) {
        if(d1[i] == INF || d2[i] == INF) {
            continue;
        }
        res = max(res, (T - d1[i] - d2[i])*A[i]);
    }
    cout << res << endl;
}