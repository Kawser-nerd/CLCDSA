#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>

int main() {
  size_t H, W;
  scanf("%zu %zu", &H, &W);

  std::vector<std::vector<int>> a(H, std::vector<int>(W));
  for (auto& ai: a)
    for (auto& aij: ai)
      scanf("%d", &aij);

  std::vector<std::tuple<size_t, size_t, size_t, size_t>> res;
  for (size_t i = 0; i < H; ++i) {
    for (size_t j = 0; j < W; ++j) {
      if (a[i][j] % 2 == 0) continue;
      if (i+1 == H && j+1 == W) continue;
      size_t ni = i;
      size_t nj = j;
      ++((j+1 == W)? ni:nj);
      res.emplace_back(i+1, j+1, ni+1, nj+1);
      --a[i][j];
      ++a[ni][nj];
    }
  }

  printf("%zu\n", res.size());
  for (const auto& p: res) {
    size_t i, j, ni, nj;
    std::tie(i, j, ni, nj) = p;
    printf("%zu %zu %zu %zu\n", i, j, ni, nj);
  }
}