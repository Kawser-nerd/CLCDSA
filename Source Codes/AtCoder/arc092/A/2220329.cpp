#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <random>
#include <unordered_map>
#define ll long long
#define fr(i,k,N) for(ll i=k; i<N;i++)
#define rep(i,N) for(ll i=0; i<N;i++)
#define alll(v) v.begin(),v.end()
using namespace std;
template <class X> void pr(X test){cout<<test<<endl;}
template <class X> void prr(X test){for(auto it:test){cout<<it;}cout<<endl;}

#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())

const long long INF = (1ll << 50);
struct graph {
    typedef long long flow_type;
    struct edge {
        int src, dst;
        flow_type capacity, flow;
        size_t rev;
    };
    int n;
    vector<vector<edge>> adj;
    graph(int n) : n(n), adj(n) { }
    void add_edge(int src, int dst, flow_type capacity) {
        adj[src].push_back({src, dst, capacity, 0, adj[dst].size()});
        adj[dst].push_back({dst, src, 0, 0, adj[src].size()-1});
    }
    flow_type max_flow(int s, int t) {
        vector<int> level(n), iter(n);
        function<int(void)> levelize = [&]() { // foward levelize
            level.assign(n, -1); level[s] = 0;
            queue<int> Q; Q.push(s);
            while (!Q.empty()) {
                int u = Q.front(); Q.pop();
                if (u == t) break;
                for (auto &e: adj[u]) {
                    if (e.capacity > e.flow && level[e.dst] < 0) {
                        Q.push(e.dst);
                        level[e.dst] = level[u] + 1;
                    }
                }
            }
            return level[t];
        };
        function<flow_type(int, flow_type)> augment = [&](int u, flow_type cur) {
            if (u == t) return cur;
            for (int &i = iter[u]; i < adj[u].size(); ++i) {
                edge &e = adj[u][i], &r = adj[e.dst][e.rev];
                if (e.capacity > e.flow && level[u] < level[e.dst]) {
                    flow_type f = augment(e.dst, min(cur, e.capacity - e.flow));
                    if (f > 0) {
                        e.flow += f;
                        r.flow -= f;
                        return f;
                    }
                }
            }
            return flow_type(0);
        };
        for (int u = 0; u < n; ++u) // initialize
            for (auto &e: adj[u]) e.flow = 0;
        
        flow_type flow = 0;
        while (levelize() >= 0) {
            fill(all(iter), 0);
            for (flow_type f; (f = augment(s, INF)) > 0; )
                flow += f;
        }
        return flow;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n),d(n);
    rep(i, n) cin>>a[i]>>b[i];
    rep(i, n) cin>>c[i]>>d[i];
    graph g(2*n+3);
    unordered_map<int, int> m;
    rep(i, n) {g.add_edge(i, 2*n+1, 1);}
    rep(i, n) {g.add_edge(2*n+2,i+n, 1);}
    rep(i, n){
        rep(j, n){
            if(a[i]<c[j] && b[i]<d[j]){
                g.add_edge(i+n, j, 1);}
        }
    }

    
    printf("%lld\n", g.max_flow(2*n+2, 2*n+1));
    
//    for (int n, m; scanf("%d %d", &n, &m) == 2; ) {
//
//        for (int i = 0; i < m; ++i) {
//            int u, v, w;
//            scanf("%d %d %d", &u, &v, &w);
//            //g.add_edge(u, v, w);
//            g.add_edge(u-1, v-1, w);
//        }
//        printf("%lld\n", g.max_flow(0, n-1));
//    }
}