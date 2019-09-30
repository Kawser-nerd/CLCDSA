#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> x(100001);
  for (size_t i = 0; i < N; ++i) {
    int a;
    scanf("%d", &a);
    if (a > 0) ++x[a-1];
    ++x[a];
    ++x[a+1];
  }

  printf("%d\n", *std::max_element(x.begin(), x.end()));
}