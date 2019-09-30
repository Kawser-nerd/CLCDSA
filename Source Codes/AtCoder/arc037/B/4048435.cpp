/**
 * @brief AtCoder Regular Contest 037<br>
 * B - ??????
 *
 * DFS????
 * @see https://arc037.contest.atcoder.jp/tasks/arc037_b
 */
#include <iostream>
using namespace std;

constexpr int MAX_N = 100;

int N, M;
bool UV[MAX_N + 1][MAX_N + 1];
bool used[MAX_N + 1];

bool dfs(int prev, int cur) {
  if (used[cur]) return true;
  used[cur] = true;

  bool result{false};
  for (int i{1}; i <= N; ++i) {
    if (i == prev) continue;
    if (UV[cur][i]) {
      result |= dfs(cur, i);
    }
  }

  return result;
}

int main() {
  cin >> N >> M;
  int u, v;
  for (int i{}; i < M; ++i) {
    cin >> u >> v;
    UV[u][v] = UV[v][u] = true;
  }

  int result{};;
  for (int i{1}; i <= N; ++i) {
    if (used[i]) continue;
    if (!dfs(0, i)) ++result;
  }
  cout << result << endl;
  return 0;
}