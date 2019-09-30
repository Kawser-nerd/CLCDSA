#include <cstdio>
#include <vector>

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  std::vector<int> B(M, 1);
  for (size_t i = 0; i < N; ++i) {
    size_t K;
    scanf("%zu", &K);

    std::vector<size_t> A(M, 0);
    for (size_t i = 0; i < K; ++i) {
      size_t a;
      scanf("%zu", &a);
      --a;
      A[a] = 1;
    }
    for (size_t i = 0; i < M; ++i)
      if (A[i] == 0) B[i] = 0;
  }

  int res = 0;
  for (size_t i = 0; i < M; ++i)
    if (B[i]) ++res;

  printf("%d\n", res);
}