#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    
    int start_i, start_j;
    vector<string> mat(n);
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
        for (int j = 0; j < m; ++j)
            if (mat[i][j] == 'S')
                start_i = i,
                start_j = j,
                mat[i][j] = '.';
    }

    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
    
    // Do BFS from start
    queue<pair<int, int>> q;
    q.emplace(start_i, start_j);
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    dist[start_i][start_j] = 0;
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int newi = i + dx[d];
            int newj = j + dy[d];

            if (newi < 0 or newj < 0 or newi >= n or newj >= m) 
                continue;
            
            if (mat[newi][newj] != '#' and dist[newi][newj] == -1) {
                dist[newi][newj] = dist[i][j] + 1;
                q.emplace(newi, newj);
            }
        }
    }

    int ans = n * m;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dist[i][j] == -1 or dist[i][j] > k)
                continue;
            
            int dist_edge = min(min(i, j), min(n - i - 1, m - j - 1));
            ans = min(ans, 1 + (dist_edge + k - 1) / k);
        }
    }

    cout << ans << endl;
    
    return 0;
}