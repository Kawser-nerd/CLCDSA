#include <iostream>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

#define MAX_N 100
#define MAX_M (MAX_N*(MAX_N-1)/2)

int N, M;

bool uv[MAX_N+1][MAX_N+1];

bool reached[MAX_N + 1];

bool dfs(int prev, int n) {
  if (reached[n]) {
    return true;
  }
  reached[n] = true;

  bool ret{};
  for (int i{1}; i <= N; ++i) {
    if (i == prev || !uv[n][i]) continue;
    ret |= dfs(n, i);
  }

  return ret;
}

int  main() {
  int u, v;
  scanf("%d%d", &N, &M);
  for (int i{}; i < M; ++ i) {
    scanf("%d%d", &u, &v);
    uv[u][v] = true;
    uv[v][u] = true;
  }

  int count{};
  for (int i{1}; i <= N; ++i) {
    if (!dfs(0, i)) ++count;
  }

  printf("%d\n", count);
}