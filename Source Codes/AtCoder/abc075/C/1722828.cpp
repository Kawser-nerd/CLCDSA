#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int nodes, edges;
  cin >> nodes >> edges;

  vector<vector<bool>> connected(nodes, vector<bool>(nodes));

  for (int i = 0, a, b; i < edges; ++i) {
    cin >> a >> b;
    a--;
    b--;
    connected[a][b] = true;
    connected[b][a] = true;
  }

  int bridges = 0;

  for (int i = 0; i < nodes; ++i) {
    for (int j = 0; j < nodes; ++j) {
      if (!connected[i][j])
        continue;

      connected[i][j] = false;
      int count = 0;

      vector<bool> visited(nodes, false);

      auto dfs = [&](int node, auto dfs)->void {
        visited[node] = true;
        count++;
        for (int k = 0; k < nodes; ++k)
          if (!visited[k] && connected[node][k])
            dfs(k, dfs);
      };

      dfs(0, dfs);

      if (count < nodes)
        bridges++;

      connected[i][j] = true;
    }
  }

  cout << bridges;
}