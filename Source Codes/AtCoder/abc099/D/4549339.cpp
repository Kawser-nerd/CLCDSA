#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

int main() {
  size_t N, C;
  scanf("%zu %zu", &N, &C);

  std::vector<std::vector<int>> D(C, std::vector<int>(C));
  for (auto& di: D)
    for (auto& dij: di)
      scanf("%d", &dij);

  std::vector<std::vector<int>> c(N, std::vector<int>(N));
  for (auto& ci: c)
    for (auto& cij: ci)
      scanf("%d", &cij);

  std::vector<std::vector<int>> g(3);
  for (size_t i = 0; i < N; ++i)
    for (size_t j = 0; j < N; ++j)
      g[(i+j) % 3].push_back(c[i][j]);

  std::vector<std::vector<int>> d(3, std::vector<int>(C));
  for (size_t i = 0; i < 3; ++i)
    for (size_t j = 0; j < C; ++j)
      for (size_t k = 0; k < g[i].size(); ++k)
        d[i][j] += D[g[i][k]-1][j];

  int res = 1e9;
  for (size_t i = 0; i < C; ++i)
    for (size_t j = 0; j < C; ++j) {
      if (j == i) continue;
      for (size_t k = 0; k < C; ++k) {
        if (k == i || k == j) continue;
        res = std::min(res, d[0][i]+d[1][j]+d[2][k]);
      }
    }

  printf("%d\n", res);
}