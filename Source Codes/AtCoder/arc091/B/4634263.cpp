#include <cstdio>
#include <cstdint>
#include <algorithm>

int main() {
  intmax_t N, K;
  scanf("%jd %jd", &N, &K);

  if (K == 0)
    return !printf("%jd\n", N*N);

  intmax_t res = 0;
  for (int b = K+1; b <= N; ++b) {
    intmax_t unit = std::max<intmax_t>(0, b-K);
    intmax_t rem = std::max<intmax_t>(0, N%b-(K-1));
    res += N/b*unit + rem;
  }

  printf("%jd\n", res);
}