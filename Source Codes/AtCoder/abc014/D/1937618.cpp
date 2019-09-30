#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;
using std::swap;

using std::fixed;
using std::setprecision;
using std::setw;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

template <class T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
    for (T e : v) {
        os << e << " ";
    }
    return os;
}

class lowest_common_ancestor {
   private:
    int n;
    int m;
    vector<vector<int>> par;
    vector<int> dep;

    int log2_int(int n) {
        int m = 0;
        while ((1 << m) < n) {
            m++;
        }
        return m;
    }

    void dfs(const vector<vector<int>>& g, int d, int p, int v) {
        dep[v] = d;
        par[0][v] = p;

        for (int u : g[v]) {
            if (par[0][u] == -1) {
                dfs(g, d + 1, v, u);
            }
        }
    }

    void init(const vector<vector<int>>& g) {
        // build par, dep
        dfs(g, 0, 0, 0);

        // doubling
        for (int i = 1; i < m; i++) {
            for (int v = 0; v < n; v++) {
                par[i][v] = par[i - 1][par[i - 1][v]];
            }
        }
    }

   public:

    lowest_common_ancestor(vector<vector<int>>& g)
        : n(g.size()),
          m(log2_int(g.size())),
          par(log2_int(g.size()), vector<int>(g.size(), -1)),
          dep(n) {
        init(g);
    }

    int depth(int v) { return dep[v]; }

    int ancestor(int v, int d) {
        if (d >= n) {
            return 0;
        }

        int a = v;
        for (int i = 0; i < m; i++) {
            if (d & (1 << i)) {
                a = par[i][a];
            }
        }

        return a;
    }

    int query(int u, int v) {
        if (dep[u] < dep[v]) {
            swap(u, v);
        }
        u = ancestor(u, dep[u] - dep[v]);

        if (u == v) {
            return u;
        }

        // (lb, ub]
        int lb = 0;
        int ub = n;
        while (ub - lb > 1) {
            int mid = lb + (ub - lb) / 2;
            if (ancestor(u, mid) == ancestor(v, mid)) {
                ub = mid;
            } else {
                lb = mid;
            }
        }

        return ancestor(u, ub);
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    lowest_common_ancestor lca(g);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        int c = lca.query(a, b);
        int la = lca.depth(a) - lca.depth(c);
        int lb = lca.depth(b) - lca.depth(c);

        cout << (la + lb + 1) << endl;
    }

    return 0;
}