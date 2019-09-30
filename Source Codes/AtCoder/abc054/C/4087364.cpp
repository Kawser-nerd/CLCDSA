/**
 * @brief AtCoder Beginner Contest 054<br>
 * C - One-stroke Path
 *
 * dfs????
 * @see https://atcoder.jp/contests/abc054/tasks/abc054_c
 */
#include <iostream>
using namespace std;

constexpr int MAX_N = 8;
int N, M;
bool graph[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1];

int dfs(int v) {
  for (int i{1}; i <= N; ++i) {
    if (!visited[i])
      goto CONTINUED;
  }
  return 1;
  CONTINUED:
  int count{};
  for (int i{1}; i <= N; ++i) {
    if (!graph[v][i] || visited[i]) continue;
    visited[i] = true;
    count += dfs(i);
    visited[i] = false;
  }
  return count;
}

int main() {
  cin >> N >> M;
  int a, b;
  for (int i{}; i < M; ++i) {
    cin >> a >> b;
    graph[a][b] = true;
    graph[b][a] = true;
  }

  visited[1] = true;
  cout << dfs(1);
  return 0;
}