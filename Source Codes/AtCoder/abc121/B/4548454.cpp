#include <cstdio>
#include <vector>

int main() {
  size_t N, M;
  int C;
  scanf("%zu %zu %d", &N, &M, &C);

  std::vector<int> b(M);
  for (auto& bi: b) scanf("%d", &bi);

  int res = 0;
  for (size_t i = 0; i < N; ++i) {
    int lhs = C;
    for (size_t j = 0; j < M; ++j) {
      int a;
      scanf("%d", &a);
      lhs += a*b[j];
    }
    if (lhs > 0) ++res;
  }

  printf("%d\n", res);
}