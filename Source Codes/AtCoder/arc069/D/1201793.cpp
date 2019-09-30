#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <cmath>
#include <cstdlib>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < int(n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using namespace std;
template <class T> inline void setmin(T & a, T const & b) { a = min(a, b); }
template <class T> inline void setmax(T & a, T const & b) { a = max(a, b); }

struct strongly_connected_components {
    static pair<int,vector<int> > decompose(vector<vector<int> > const & g) { // adjacent list
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

vector<bool> twosat(int n, vector<pair<int, int> > const & cnf) {
    // make digraph
    vector<vector<int> > g(2*n);
    auto i = [&](int x) { assert (x != 0 and abs(x) <= n); return x > 0 ? x-1 : n-x-1; };
    for (auto it : cnf) {
        int x, y; tie(x, y) = it; // x or y
        g[i(- x)].push_back(i(y)); // not x implies y
        g[i(- y)].push_back(i(x)); // not y implies x
    }
    // do SCC
    vector<int> component = strongly_connected_components::decompose(g).second;
    vector<bool> valuation(n);
    repeat_from (x,1,n+1) {
        if (component[i(x)] == component[i(- x)]) { // x iff not x
            return vector<bool>(); // unsat
        }
        valuation[x-1] = component[i(x)] > component[i(- x)]; // use components which indices are large
    }
    return valuation;
}

int main() {
    int n; scanf("%d", &n);
    vector<int> x(n), y(n); repeat (i,n) scanf("%d%d", &x[i], &y[i]);
    int segtree_n = 2*pow(2, ceil(log2(n)));
    auto is_x = [&](int i) { return    2*segtree_n+i; };
    auto is_y = [&](int i) { return - (2*segtree_n+i); };
    auto dist = [&](int p) { return p > 0 ? x[p-2*segtree_n] : y[-p-2*segtree_n]; };
    vector<int> ps(2*n);
    repeat (i,n) {
        ps[2*i  ] = is_x(i);
        ps[2*i+1] = is_y(i);
    }
    whole (sort, ps, [&](int p, int q) { return dist(p) < dist(q); });
    auto pred = [&](int limit) {
        vector<pair<int, int> > cnf;
        auto implies = [&](int i, int j) { cnf.emplace_back(- i, j); };
        repeat_from (i,1,segtree_n) {
            int l = 2*i;
            int r = 2*i+1;
            implies(l, i);
            implies(r, i);
        }
        repeat (i,2*n) {
            implies(segtree_n+i, ps[i]);
            implies(ps[i], segtree_n+i);
        }
        int l = 0;
        vector<bool> disjoint(2*segtree_n);
        repeat_from (r,1,2*n+1) {
            while (dist(ps[l]) + limit <= dist(ps[r-1])) ++ l;
            vector<int> acc; {
                int il = l;
                int ir = r;
                for (il += segtree_n, ir += segtree_n; il < ir; il /= 2, ir /= 2) {
                    if (il % 2 == 1) acc.push_back(il ++);
                    if (ir % 2 == 1) acc.push_back(-- ir);
                }
            }
            repeat (j, acc.size()) {
                disjoint[acc[j]] = true;
                repeat (i, j) if (i != j) {
                    implies(acc[i], - acc[j]);
                    implies(acc[j], - acc[i]);
                }
            }
        }
        repeat_from (i,1,segtree_n) {
            if (disjoint[i]) {
                int l = 2*i;
                int r = 2*i+1;
                implies(l, - r);
                implies(r, - l);
                disjoint[l] = true;
                disjoint[r] = true;
            }
        }
        return not twosat(2*segtree_n-1+n, cnf).empty();
    };
    int l = 0, r = 1e9+7;
    repeat (i,n) {
        repeat (j,n) if (i != j) {
            int acc = 0;
            setmax(acc, abs(x[i] - x[j]));
            setmax(acc, abs(x[i] - y[j]));
            setmax(acc, abs(y[i] - x[j]));
            setmax(acc, abs(y[i] - y[j]));
            setmin(r, acc+1);
        }
    }
    while (l + 1 < r) {
        int m = (l + r) / 2;
        (pred(m) ? l : r) = m;
    }
    printf("%d\n", l);
    return 0;
}