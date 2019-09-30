#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <tuple>

int main() {
  size_t N, K;
  scanf("%zu %zu", &N, &K);

  std::vector<std::pair<int, size_t>> ab(N);
  for (size_t i = 0; i < N; ++i)
    scanf("%d %zu", &ab[i].first, &ab[i].second);

  std::sort(ab.begin(), ab.end());
  for (const auto& p: ab) {
    int a;
    size_t b;
    std::tie(a, b) = p;
    if (b >= K)
      return !printf("%d\n", a);

    K -= b;
  }
  return 1;
}