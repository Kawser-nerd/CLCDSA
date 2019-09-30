#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
  size_t H, W;
  int D;
  scanf("%zu %zu %d", &H, &W, &D);

  std::vector<std::pair<int, int>> B(H*W);

  for (size_t i = 0; i < H; ++i) {
    for (size_t j = 0; j < W; ++j) {
      int a;
      scanf("%d", &a);
      --a;
      B[a] = {i, j};
    }
  }

  std::vector<std::vector<std::pair<int, int>>> C(D);
  for (size_t i = 0; i < H*W; ++i)
    C[i % D].push_back(B[i]);

  std::vector<std::vector<int>> acc(D);
  for (int i = 0; i < D; ++i) {
    acc[i] = {0};
    for (size_t j = 1; j < C[i].size(); ++j) {
      int dy = std::abs(C[i][j-1].first - C[i][j].first);
      int dx = std::abs(C[i][j-1].second - C[i][j].second);
      acc[i].push_back(acc[i][j-1]+dx+dy);
    }
  }

  int Q;
  scanf("%d", &Q);

  for (int i = 0; i < Q; ++i) {
    int L, R;
    scanf("%d %d", &L, &R);
    --L;
    --R;
    printf("%d\n", acc[R % D][R / D] - acc[L % D][L / D]);
  }
}