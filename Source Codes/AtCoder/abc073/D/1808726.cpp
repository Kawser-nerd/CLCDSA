#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::min;

const int INF = 1e8;

int backtrack(const vector<int>& t, const vector<vector<int>>& g,
              vector<bool>& used, int prev = -1, int sum = 0, int best = INF,
              size_t depth = 0) {

    if (depth >= t.size()) {
        return min(best, sum);
    }

    for (size_t i = 0; i < t.size(); i++) {
        if (used[i]) {
            continue;
        }
        used[i] = true;

        const int cost = prev == -1 ? 0 : g[t[prev]][t[i]];
        best = min(best, backtrack(t, g, used, i, sum + cost, best, depth + 1));

        used[i] = false;
    }

    return best;
}

int main(void) {
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> town(r);
    for (int i = 0; i < r; i++) {
        int t;
        cin >> t;
        town[i] = t - 1;
    }

    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
        graph[b - 1][a - 1] = c;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    vector<bool> used(town.size());
    cout << backtrack(town, graph, used) << endl;

    return 0;
}