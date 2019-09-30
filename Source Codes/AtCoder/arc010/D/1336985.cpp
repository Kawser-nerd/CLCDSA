#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>
#include <climits>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < (n); ++(i))
typedef long long ll;
using namespace std;

pair<int, vector<int> > decompose_to_strongly_connected_components(vector<vector<int> > const & g) {
    int n = g.size();
    auto & to = g;
    vector<vector<int> > from(n);
    repeat (i, n) for (int j : to[i]) from[j].push_back(i);
    vector<int> acc(n); {
        auto it = acc.rbegin();
        vector<int> used(n, -1);
        stack<int> stk;
        repeat (k, n) if (used[k] == -1) {
            stk.push(k);
            used[k] = 0;
            while (not stk.empty()) { // dfs
                int i = stk.top();
                while (used[i] < to[i].size()) {
                    int j = to[i][used[i]];
                    ++ used[i];
                    if (used[j] == -1) {
                        stk.push(j);
                        used[j] = 0;
                        break;
                    }
                }
                if (stk.top() == i) {
                    *(it ++) = i;
                    stk.pop();
                }
            }
        }
    }
    int count = 0;
    vector<int> component_of(n); {
        vector<bool> used(n);
        stack<int> stk;
        for (int k : acc) if (not used[k]) {
            stk.push(k);
            used[k] = true;
            while (not stk.empty()) { // dfs
                int i = stk.top(); stk.pop();
                component_of[i] = count;
                for (int j : from[i]) if (not used[j]) {
                    stk.push(j);
                    used[j] = true;
                }
            }
            ++ count;
        }
    }
    return { count, move(component_of) };
}

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
        auto p = decompose_to_strongly_connected_components(g);
        auto f = components_graph(p.first, p.second, g);
        cout << count_roots(p.first, f) << endl;
    }
    return 0;
}