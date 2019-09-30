#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
  size_t N, K;
  scanf("%zu %zu", &N, &K);

  std::vector<int> l(N);
  for (auto& li: l) scanf("%d", &li);

  std::sort(l.rbegin(), l.rend());
  printf("%d\n", std::accumulate(l.begin(), l.begin()+K, 0));
}