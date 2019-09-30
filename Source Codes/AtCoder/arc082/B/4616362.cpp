#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<size_t> p(N);
  for (auto& pi: p) {
    scanf("%zu", &pi);
    --pi;
  }

  int res = 0;
  for (size_t i = 0; i+1 < N; ++i) {
    if (p[i] == i) {
      ++res;
      std::swap(p[i], p[i+1]);
    }
  }

  if (p[N-1] == N-1) ++res;
  printf("%d\n", res);
}