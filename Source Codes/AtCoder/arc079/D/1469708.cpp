#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using namespace std;

template <typename C>
int mex(C const & xs) {
    int y = 0;
    for (int x : xs) { // xs must be sorted (duplication is permitted)
        if (y <  x) break;
        if (y == x) ++ y;
    }
    return y;
}

vector<int> func(vector<int> a, int n, vector<vector<int> > const & g, vector<vector<int> > const & h) {
    vector<int> outdegree(n);
    queue<int> que;
    repeat (i, n) {
        outdegree[i] = g[i].size();
        for (int j : g[i]) {
            if (a[j] != -1) {
                outdegree[i] -= 1;
            }
        }
        if (outdegree[i] == 0 and a[i] == -1) {
            que.push(i);
        }
    }
    while (not que.empty()) {
        int i = que.front(); que.pop();
        assert (outdegree[i] == 0);
        assert (a[i] == -1);
        set<int> gs;
        for (int j : g[i]) {
            assert (a[j] != -1);
            gs.insert(a[j]);
        }
        a[i] = mex(gs);
        for (int j : h[i]) if (outdegree[j] != 0) {
            outdegree[j] -= 1;
            if (outdegree[j] == 0 and a[j] == -1) {
                que.push(j);
            }
        }
    }
    return a;
}

int mex_node(int i, vector<int> const & a, vector<vector<int> > const & g) {
    set<int> gs;
    for (int j : g[i]) {
        if (a[j] != -1) {
            gs.insert(a[j]);
        }
    }
    return mex(gs);
}

bool solve(int n, vector<vector<int> > const & g, vector<vector<int> > const & h) {
    vector<int> a(n, -1);
    a = func(a, n, g, h);
    if (whole(count, a, -1) == 0) return true;
    int i = -1;
    repeat (k, n) if (a[k] == -1) { i = k; break; }
    assert (i != -1);
    int j = -1;
    for (int k : g[i]) if (a[k] == -1) { j = k; break; }
    assert (j != -1);
    int g1 = mex_node(i, a, g);
    a[j] = g1;
    int g2 = mex_node(i, a, g);
    a[j] = -1;
    for (int a_i : { g1, g2 }) {
        vector<int> b = a;
        b[i] = a_i;
        b = func(b, n, g, h);
        assert (b[j] != -1);
        if (mex_node(i, b, g) == a_i) return true;
    }
    return false;
}

int main() {
    int n; scanf("%d", &n);
    vector<vector<int> > g(n);
    vector<vector<int> > h(n);
    repeat (i, n) {
        int p; scanf("%d", &p); -- p;
        g[p].push_back(i);
        h[i].push_back(p);
    }
    bool result = solve(n, g, h);
    printf("%s\n", result ? "POSSIBLE" : "IMPOSSIBLE");
    return 0;
}