#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  int INF = 1e9;
  std::vector<std::vector<int>> g(N, std::vector<int>(N, INF));
  for (size_t i = 0; i < N; ++i)
    g[i][i] = 0;

  for (size_t i = 0; i < M; ++i) {
    size_t a, b;
    int c;
    scanf("%zu %zu %d", &a, &b, &c);
    --a;
    --b;
    g[a][b] = g[b][a] = c;
  }

  std::vector<std::vector<int>> d = g;
  for (size_t k = 0; k < N; ++k)
    for (size_t i = 0; i < N; ++i)
      for (size_t j = 0; j < N; ++j)
        d[i][j] = std::min(d[i][j], d[i][k]+d[k][j]);

  int res = 0;
  for (size_t i = 0; i < N; ++i)
    for (size_t j = 0; j < i; ++j)
      if (g[i][j] < INF && d[i][j] != g[i][j])
        ++res;

  printf("%d\n", res);
}