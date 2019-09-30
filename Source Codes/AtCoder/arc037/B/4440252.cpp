#include <iostream>
using namespace std;

constexpr int MAX_N = 100;

int N, M;
bool edge[MAX_N + 1][MAX_N + 1];
bool reached[MAX_N + 1];

bool dfs(int v, int prev) {
  reached[v] = true;

  bool ret{false};
  for (int i{1}; i <= N; ++i) {
    if (i == v || i == prev || !edge[v][i])
      continue;
    if (reached[i])
      return true;
    ret |= dfs(i, v);
  }

  return ret;
}

int main() {
  cin >> N >> M;
  for (int i{}; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    edge[u][v] = edge[v][u] = true;
  }

  int tree{};
  for (int i{1}; i <= N; ++i) {
    if (reached[i])
      continue;
    if (!dfs(i, 0))
      ++tree;
  }

  cout << tree << endl;
  return 0;
}