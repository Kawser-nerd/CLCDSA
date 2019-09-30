#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <algorithm>
#include <vector>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<intmax_t> a(N);
  intmax_t sum = 0;
  for (auto& ai: a) {
    scanf("%jd", &ai);
    sum += ai;
  }

  intmax_t x = a[0];
  intmax_t res = std::abs(x-(sum-x));
  for (size_t i = 1; i+1 < N; ++i) {
    x += a[i];
    intmax_t y = sum-x;
    res = std::min(res, std::abs(x-y));
  }
  printf("%jd\n", res);
}