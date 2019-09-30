#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

std::vector<intmax_t> divisor(intmax_t n) {
  std::vector<intmax_t> res;
  for (intmax_t i = 1; i*i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n/i)
        res.push_back(n/i);
    }
  }
  std::sort(res.begin(), res.end());
  return res;
}

int main() {
  intmax_t N, M;
  scanf("%jd %jd", &N, &M);

  auto ds = divisor(M);
  intmax_t res = 1;
  for (auto d: ds)
    if (M/d >= N) res = d;

  printf("%jd\n", res);
}