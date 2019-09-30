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

vector<int> dfs(int n, const vector<vector<int>>& g, int v, int t,
                vector<bool>& visited) {
    if (v == t) {
        vector<int> ans;
        ans.push_back(v);
        return ans;
    }

    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (g[v][i] > 0 && !visited[i]) {
            vector<int> ans = dfs(n, g, i, t, visited);
            if (ans.size() > 0) {
                ans.push_back(v);
                return ans;
            }
        }
    }

    return vector<int>();
}

int maxflow(int n, vector<vector<int>>& g, int s, int t) {
    int cnt = 0;
    while (1) {
        vector<bool> visited(n);
        vector<int> route = dfs(n, g, s, t, visited);
        if (route.size() == 0) {
            break;
        }

        std::reverse(route.begin(), route.end());

        int m = route.size();
        for (int i = 0; i < m - 1; i++) {
            int a = route[i];
            int b = route[i + 1];
            g[a][b]--;
            g[b][a]++;
        }
        cnt++;
    }
    return cnt;
}

int main() {
    int n, g, e;
    cin >> n >> g >> e;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1));
    for (int i = 0; i < g; i++) {
        int p;
        cin >> p;
        graph[p][n] = graph[n][p] = 1;
    }

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }

    cout << maxflow(n + 1, graph, 0, n) << endl;

    return 0;
}