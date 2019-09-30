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

using std::fixed;
using std::setprecision;
using std::setw;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

class union_find {
   private:
    vector<int> p;
    vector<int> h;
    vector<int> w;

   public:
    union_find(int n) : p(n, -1), h(n, 0), w(n, 1) {}

    int find(int u) {
        if (p[u] == -1) {
            return u;
        }
        return p[u] = find(p[u]);
    }

    void unite(int u, int v) {
        const int u_rt = find(u);
        const int v_rt = find(v);

        if (u_rt == v_rt) {
            return;
        }

        if (h[u_rt] > h[v_rt]) {
            p[v_rt] = u_rt;
            w[u_rt] += w[v_rt];
        } else {
            p[u_rt] = v_rt;
            w[v_rt] += w[u_rt];
            if (h[u_rt] == h[v_rt]) {
                h[v_rt]++;
            }
        }
    }

    int weight(int u) { return w[find(u)]; }
    bool same(int u, int v) { return find(u) == find(v); }
};

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    s--;

    vector<vector<int>> g(n);
    g[s].push_back(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[min(u, v)].push_back(max(u, v));
    }

    union_find uf(n + 1);
    vector<bool> ans(n);
    for (int v = n - 1; v >= 0; v--) {
        for (int u : g[v]) {
            uf.unite(v, u);
        }
        if (uf.same(n, v)) {
            ans[v] = true;
        }
    }

    for (int v = 0; v < n; v++) {
        if (ans[v]) {
            cout << v + 1 << endl;
        }
    }

    return 0;
}