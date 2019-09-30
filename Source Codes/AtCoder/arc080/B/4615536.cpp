#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  size_t H, W, N;
  scanf("%zu %zu %zu", &H, &W, &N);

  std::vector<int> cc;
  cc.reserve(H*W);
  for (size_t i = 1; i <= N; ++i) {
    int a;
    scanf("%d", &a);
    for (int j = 0; j < a; ++j)
      cc.push_back(i);
  }
  
  std::vector<std::vector<int>> res(H, std::vector<int>(W));
  for (size_t i = 0; i < H; ++i) {
    if (i % 2 == 0) {
      for (size_t j = 0; j < W; ++j)
        res[i][j] = cc[i*W+j];
    } else {
      for (size_t j = W; j--;)
        res[i][j] = cc[i*W+W-j-1];
    }
  }

  for (size_t i = 0; i < H; ++i)
    for (size_t j = 0; j < W; ++j)
      printf("%d%c", res[i][j], j+1<W? ' ':'\n');
}