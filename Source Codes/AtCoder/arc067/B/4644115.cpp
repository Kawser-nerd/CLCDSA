#include <cstdio>
#include <cstdint>
#include <vector>

int main() {
  size_t N;
  intmax_t A, B;
  scanf("%zu %jd %jd", &N, &A, &B);

  std::vector<intmax_t> X(N);
  for (auto& xi: X) scanf("%jd", &xi);

  intmax_t res = 0;
  for (size_t i = 1; i < N; ++i)
    res += std::min(A*(X[i]-X[i-1]), B);

  printf("%jd\n", res);
}