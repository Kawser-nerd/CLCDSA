#include <cstdio>
#include <algorithm>

int main() {
  size_t N, K;
  scanf("%zu %zu", &N, &K);

  printf("%zu\n", (N+K-3)/(K-1));
}