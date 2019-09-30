#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  int X;
  scanf("%zu %d", &N, &X);

  std::vector<int> m(N);
  int sum = 0;
  for (auto& mi: m) {
    scanf("%d", &mi);
    sum += mi;
  }

  int min = *std::min_element(m.begin(), m.end());
  int res = N;
  
  X -= sum;
  res += X / min;
  printf("%d\n", res);
}