#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  int Z, W;
  scanf("%zu %d %d", &N, &Z, &W);

  std::vector<int> a(N);
  for (auto& ai: a) scanf("%d", &ai);

  if (N == 1)
    return !printf("%d\n", abs(a[0]-W));

  printf("%d\n", std::max(abs(a[N-1]-W), abs(a[N-1]-a[N-2])));
}