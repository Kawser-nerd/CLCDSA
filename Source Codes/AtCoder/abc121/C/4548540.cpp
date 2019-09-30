#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

int main() {
  size_t N;
  int M;
  scanf("%zu %d", &N, &M);

  std::vector<std::pair<int, int>> AB(N);
  for (auto& p: AB)
    scanf("%d %d", &p.first, &p.second);

  std::sort(AB.begin(), AB.end());

  intmax_t res = 0;
  for (const auto& p: AB) {
    intmax_t a, b;
    std::tie(a, b) = p;

    if (M > b) {
      M -= b;
      res += a*b;
    } else {
      res += a*M;
      break;
    }
  }

  printf("%jd\n", res);
}