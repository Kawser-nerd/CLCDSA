#include <cstdio>
#include <algorithm>

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  int res = 0;
  for (int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    res += std::min(K-x, x);
  }
  res *= 2;
  printf("%d\n", res);
}