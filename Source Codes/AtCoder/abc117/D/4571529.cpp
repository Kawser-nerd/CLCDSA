#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

intmax_t f(const std::vector<intmax_t>& A, intmax_t X) {
  intmax_t res = 0;
  for (auto ai: A) res += ai ^ X;
  return res;
}

int main() {
  size_t N;
  intmax_t K;
  scanf("%zu %jd", &N, &K);

  std::vector<intmax_t> A(N);
  std::vector<size_t> B(40);
  for (auto& ai: A) {
    scanf("%jd", &ai);
    for (int i = 0; i < 40; ++i)
      if (ai >> i & 1)
        ++B[i];
  }

  intmax_t L = 0;
  for (int i = 0; i < 40; ++i)
    if (B[i] < N-B[i]) L |= 1L << i;

  intmax_t res = f(A, K);
  for (int i = 0; i < 40; ++i) {
    intmax_t mid = 1L << i;
    intmax_t lo = mid-1;
    intmax_t hi = ~(mid | lo);
    intmax_t X = (K & hi) | (L & lo);
    if (X > K) continue;
    res = std::max(res, f(A, X));
  }
  printf("%jd\n", res);
}