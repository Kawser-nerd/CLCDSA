#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

int main() {
  size_t N, M, Q;
  scanf("%zu %zu %zu", &N, &M, &Q);

  std::vector<std::vector<int>> A(N, std::vector<int>(N));
  for (size_t i = 0; i < M; ++i) {
    size_t L, R;
    scanf("%zu %zu", &L, &R);
    --L;
    --R;
    ++A[L][R];
  }

  std::vector<std::vector<int>> B(N+1, std::vector<int>(N+1));
  for (size_t i = 1; i <= N; ++i)
    for (size_t j = 1; j <= N; ++j)
      B[i][j] = B[i][j-1] + A[i-1][j-1];

  for (size_t i = 1; i <= N; ++i)
    for (size_t j = 1; j <= N; ++j)
      B[i][j] += B[i-1][j];

  for (size_t i = 0; i < Q; ++i) {
    size_t p, q;
    scanf("%zu %zu", &p, &q);
    --p;
    int res = B[q][q] - B[p][q] - B[q][p] + B[p][p];
    printf("%d\n", res);
  }
}