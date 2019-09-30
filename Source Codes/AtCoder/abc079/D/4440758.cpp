#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  int H, W;
  scanf("%d %d", &H, &W);

  std::vector<std::vector<int>> c(10, std::vector<int>(10));
  for (auto& ci: c)
    for (auto& cij: ci) scanf("%d", &cij);

  for (int k = 0; k < 10; ++k)
    for (int i = 0; i < 10; ++i)
      for (int j = 0; j < 10; ++j)
        c[i][j] = std::min(c[i][j], c[i][k]+c[k][j]);

  int res = 0;
  for (int i = 0; i < H*W; ++i) {
    int a;
    scanf("%d", &a);
    if (a > -1) res += c[a][1];
  }

  printf("%d\n", res);
}