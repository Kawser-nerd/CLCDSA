#include <iostream>
using namespace std;

constexpr int MAX_N = 100;

int N, M;
bool hen[MAX_N + 1][MAX_N + 1];
bool reached[MAX_N + 1];

void dfs(bool &tree, int cur, int prev) {
  reached[cur] = true;

  for (int i{1}; i <= N; ++i) {
    if (i == cur || i == prev)
      continue;
    if (hen[cur][i]) {
      if (reached[i]) {
        tree = false;
        continue;
      }
      dfs(tree, i, cur);
    }
  }
}

int main() {
  cin >> N >> M;
  for (int i{}; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    hen[u][v] = hen[v][u] = true;
  }

  int count{};
  for (int i{1}; i <= N; ++i) {
    if (reached[i])
      continue;
    bool tree{true};
    dfs(tree, i, 0);
    if (tree)
      ++count;
  }

  cout << count << endl;
  return 0;
}