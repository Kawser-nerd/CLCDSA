#include <iostream>
using namespace std;

constexpr int MAX_N = 8;
constexpr int MAX_M = MAX_N*(MAX_N-1)/2;

int N, M;
bool graph[MAX_N + 1][MAX_N + 1];
bool reached[MAX_N + 1];

int dfs(int a) {
  bool reachedAll{true};
  for (int i{1}; i <= N; ++i) {
    if (!reached[i]) {
      reachedAll = false;
      break;
    }
  }
  if (reachedAll)
    return 1;

  int count{};
  for (int b{1}; b <= N; ++b) {
    if (b == a || !graph[a][b] || reached[b])
      continue;
    reached[b] = true;
    count += dfs(b);
    reached[b] = false;
  }

  return count;
}

int main() {
  cin >> N >> M;
  for (int i{}; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a][b] = graph[b][a] = true;
  }

  reached[1] = true;
  printf("%d\n", dfs(1));
  return 0;
}