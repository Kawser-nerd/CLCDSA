#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <stack>
#include <tuple>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_reverse(i, n) for (int i = (n)-1; (i) >= 0; --(i))
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using namespace std;

/**
 * @brief 2-edge-connected components decomposition
 * @param g an adjacent list of the simple undirected graph
 * @note O(V + E)
 */
pair<int, vector<int> > decompose_to_two_edge_connected_components(vector<vector<int> > const & g) {
    int n = g.size();
    vector<int> imos(n); { // imos[i] == 0  iff  the edge i -> parent is a bridge
        vector<char> used(n);
        function<void (int, int)> go = [&](int i, int parent) {
            used[i] = 1;
            for (int j : g[i]) if (j != parent) {
                if (used[j] == 0) {
                    go(j, i);
                    imos[i] += imos[j];
                } else if (used[j] == 1) {
                    imos[i] += 1;
                    imos[j] -= 1;
                }
            }
            used[i] = 2;
        };
        repeat (i, n) if (used[i] == 0) {
            go(i, -1);
        }
    }
    int size = 0;
    vector<int> component_of(n, -1); {
        function<void (int)> go = [&](int i) {
            for (int j : g[i]) if (component_of[j] == -1) {
                component_of[j] = imos[j] == 0 ? size ++ : component_of[i];
                go(j);
            }
        };
        repeat (i, n) if (component_of[i] == -1) {
            component_of[i] = size ++;
            go(i);
        }
    }
    return { size, move(component_of) };
}
vector<vector<int> > decomposed_graph(int size, vector<int> const & component_of, vector<vector<int> > const & g) {
    int n = g.size();
    vector<vector<int> > h(size);
    repeat (i, n) for (int j : g[i]) {
        if (component_of[i] != component_of[j]) {
            h[component_of[i]].push_back(component_of[j]);
        }
    }
    repeat (k, size) {
        whole(sort, h[k]);
        h[k].erase(whole(unique, h[k]), h[k].end());
    }
    return h;
}

/**
 * @brief lowest common ancestor with doubling
 */
struct lowest_common_ancestor {
    vector<vector<int> > a;
    vector<int> depth;
    lowest_common_ancestor() = default;
    /**
     * @note O(N \log N)
     * @param g an adjacent list of the tree
     */
    lowest_common_ancestor(int root, vector<vector<int> > const & g) {
        int n = g.size();
        int log_n = max<int>(1, ceil(log2(n)));
        a.resize(log_n, vector<int>(n, -1));
        depth.resize(n, -1);
        {
            auto & parent = a[0];
            stack<int> stk;
            depth[root] = 0;
            parent[root] = -1;
            stk.push(root);
            while (not stk.empty()) {
                int x = stk.top(); stk.pop();
                for (int y : g[x]) if (depth[y] == -1) {
                    depth[y] = depth[x] + 1;
                    parent[y] = x;
                    stk.push(y);
                }
            }
        }
        repeat (k, log_n-1) {
            repeat (i, n) {
                if (a[k][i] != -1) {
                    a[k+1][i] = a[k][a[k][i]];
                }
            }
        }
    }
    /**
     * @brief find the LCA of x and y
     * @note O(log N)
     */
    int operator () (int x, int y) const {
        int log_n = a.size();
        if (depth[x] < depth[y]) swap(x,y);
        repeat_reverse (k, log_n) {
            if (a[k][x] != -1 and depth[a[k][x]] >= depth[y]) {
                x = a[k][x];
            }
        }
        assert (depth[x] == depth[y]);
        assert (x != -1);
        if (x == y) return x;
        repeat_reverse (k, log_n) {
            if (a[k][x] != a[k][y]) {
                x = a[k][x];
                y = a[k][y];
            }
        }
        assert (x != y);
        assert (a[0][x] == a[0][y]);
        return a[0][x];
    }
    /**
     * @brief find the descendant of x for y
     */
    int descendant (int x, int y) const {
        assert (depth[x] < depth[y]);
        int log_n = a.size();
        repeat_reverse (k, log_n) {
            if (a[k][y] != -1 and depth[a[k][y]] >= depth[x]+1) {
                y = a[k][y];
            }
        }
        assert (a[0][y] == x);
        return y;
    }
};

int main() {
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<int> > g(n); // connected
    repeat (i, m) {
        int x, y; scanf("%d%d", &x, &y); -- x; -- y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int size; vector<int> component_of; tie(size, component_of) = decompose_to_two_edge_connected_components(g);
    vector<vector<int> > h = decomposed_graph(size, component_of, g); // tree
    lowest_common_ancestor lca(0, h);
    auto le = [&](int x, int y) { return lca(x, y) == y; };
    int query; scanf("%d", &query);
    while (query --) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c); -- a; -- b; -- c;
        int x = component_of[a];
        int y = component_of[b];
        int z = component_of[c];
        bool result;
        if (le(x, z)) {
            result = le(x, y) and le(y, z);
        } else if (le(z, x)) {
            result = le(z, y) and le(y, x);
        } else {
            result = (le(x, y) or le(z, y)) and le(y, lca(x, z));
        }
        printf("%s\n", result ? "OK" : "NG");
    }
    return 0;
}