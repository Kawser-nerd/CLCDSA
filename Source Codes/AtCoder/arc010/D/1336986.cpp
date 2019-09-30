#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < (n); ++(i))
typedef long long ll;
using namespace std;
struct strongly_connected_components {
    static pair<int,vector<int> > decompose(vector<vector<int> > const & g) {
        strongly_connected_components scc(g);
        return { scc.k, scc.c };
    }
private:
    int n;
    vector<vector<int> > to, from;
    explicit strongly_connected_components(vector<vector<int> > const & g) : n(g.size()), to(g), from(n) {
        repeat (i,n) for (int j : to[i]) from[j].push_back(i);
        decompose();
    }
    vector<bool> used;
    vector<int> vs;
    void dfs(int i) {
        used[i] = true;
        for (int j : to[i]) if (not used[j]) dfs(j);
        vs.push_back(i);
    }
    int k; // number of scc
    vector<int> c; // i-th vertex in g is in c_i-th vertex in scc-decomposed g
    void rdfs(int i) {
        used[i] = true;
        c[i] = k;
        for (int j : from[i]) if (not used[j]) rdfs(j);
    }
    void decompose() {
        used.clear(); used.resize(n, false);
        repeat (i,n) if (not used[i]) dfs(i);
        used.clear(); used.resize(n, false);
        k = 0;
        c.resize(n);
        reverse(vs.begin(), vs.end());
        for (int i : vs) if (not used[i]) {
            rdfs(i);
            k += 1;
        }
    }
};
vector<vector<int> > components_graph(int k, vector<int> const & c, vector<vector<int> > const & g) {
    vector<vector<int> > f(k);
    repeat (i,g.size()) {
        for (int j : g[i]) {
            f[c[i]].push_back(c[j]);
        }
    }
    repeat (i,k) {
        sort(f[i].begin(), f[i].end());
        auto it = unique(f[i].begin(), f[i].end());
        it = remove(f[i].begin(), it, i);
        f[i].erase(it, f[i].end());
    }
    return f;
}
struct point_t { int y, x; };
ll sq(ll x) { return x*x; }
ll sqdist(point_t p, point_t q) {
    return sq(p.y-q.y) + sq(p.x-q.x);
}
vector<vector<int> > make_digraph(int n, vector<point_t> const & ps, int m, vector<point_t> const & qs) {
    vector<ll> rs(n, LLONG_MAX);
    repeat (i,n) {
        for (auto q : qs) {
            rs[i] = min(rs[i], sqdist(ps[i], q));
        }
    }
    vector<vector<int> > g(n); // directed graph
    repeat (i,n) {
        repeat (j,n) if (i != j) {
            if (sqdist(ps[i], ps[j]) < rs[i]) {
                g[i].push_back(j);
            }
        }
    }
    return g;
}
int count_roots(int n, vector<vector<int> > const & g) {
    vector<int> indegree(n);
    repeat (i,n) {
        for (int j : g[i]) {
            indegree[j] += 1;
        }
    }
    int result = 0;
    repeat (i,n) {
        if (indegree[i] == 0) {
            result += 1;
        }
    }
    return result;
}
int main() {
    int n; cin >> n;
    vector<point_t> ps(n); for (auto & p : ps) cin >> p.x >> p.y;
    int m; cin >> m;
    vector<point_t> qs(m); for (auto & q : qs) cin >> q.x >> q.y;
    if (m == 0) {
        cout << 1 << endl;
    } else {
        auto g = make_digraph(n, ps, m, qs);
        auto p = strongly_connected_components::decompose(g);
        auto f = components_graph(p.first, p.second, g);
        cout << count_roots(p.first, f) << endl;
    }
    return 0;
}