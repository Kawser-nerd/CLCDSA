#include <cstdio>
#include <vector>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> h(N);
  int sum = 0;
  for (auto& hi: h) {
    scanf("%d", &hi);
    sum += hi;
  }

  int res = 0;
  while (sum > 0) {
    for (size_t i = 0; i < N; ++i) {
      if (h[i] == 0) continue;
      for (size_t j = i; j < N; ++j) {
        if (h[j] == 0) break;
        --h[j];
        --sum;
      }
      ++res;
      break;
    }
  }
  printf("%d\n", res);
}