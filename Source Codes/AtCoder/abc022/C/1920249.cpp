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

pair<vector<int>, vector<int>> dijkstra(int n, const vector<vector<int>>& g,
                                        int s) {
    vector<int> d(n, INF);
    d[s] = 0;

    vector<int> p(n, -1);

    typedef pair<int, int> P;
    priority_queue<P, vector<P>, std::greater<P>> q;
    q.push(make_pair(0, s));

    while (!q.empty()) {
        P tmp = q.top();
        q.pop();

        const int c = tmp.first;
        const int v = tmp.second;
        if (c > d[v]) {
            continue;
        }

        for (int u = 0; u < n; u++) {
            if (g[v][u] == INF) {
                continue;
            }

            const int d_vu = d[v] + g[v][u];
            if (d_vu < d[u]) {
                d[u] = d_vu;
                p[u] = v;
                q.push(make_pair(d_vu, u));
            }
        }
    }

    return make_pair(d, p);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        u--;
        v--;
        g[u][v] = g[v][u] = l;
    }

    const pair<vector<int>, vector<int>> tmp0 = dijkstra(n, g, 0);
    const vector<int>& d0 = tmp0.first;
    const vector<int>& p0 = tmp0.second;

    int ans = INF;
    for (int i = 1; i < n; i++) {
        if (d0[i] == INF) {
            continue;
        }

        vector<vector<int>> h(g);
        for (int j = i; p0[j] != -1; j = p0[j]) {
            h[j][p0[j]] = h[p0[j]][j] = INF;
        }

        const pair<vector<int>, vector<int>> tmp1 = dijkstra(n, h, i);
        const vector<int>& d1 = tmp1.first;
        if (d1[0] == INF) {
            continue;
        }
        ans = min(ans, d0[i] + d1[0]);
    }

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}