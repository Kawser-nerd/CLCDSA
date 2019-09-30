#include <cstdio>
#include <cstdlib>
#include <vector>

int main() {
  size_t N, M;
  scanf("%zu %zu", &N, &M);

  std::vector<int> a(N), b(N);
  for (size_t i = 0; i < N; ++i) 
    scanf("%d %d", &a[i], &b[i]);

  std::vector<int> c(M), d(M);
  for (size_t j = 0; j < M; ++j)
    scanf("%d %d", &c[j], &d[j]);

  for (size_t i = 0; i < N; ++i) {
    size_t res = -1;
    int min = 1e9;
    for (size_t j = 0; j < M; ++j) {
      int cur = abs(a[i]-c[j]) + abs(b[i]-d[j]);
      if (min > cur) {
        min = cur;
        res = j+1;
      }
    }
    printf("%zu\n", res);
  }
}