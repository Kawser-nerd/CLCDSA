#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  int X;
  scanf("%zu %d", &N, &X);

  std::vector<int> m(N);
  for (auto& mi: m) {
    scanf("%d", &mi);
    X -= mi;
  }

  std::sort(m.begin(), m.end());
  int res = N;
  res += X / m[0];
  printf("%d\n", res);
}