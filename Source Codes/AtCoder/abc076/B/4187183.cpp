#include <cstdio>
#include <algorithm>

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  int res = 1;
  for (int i = 0; i < N; ++i)
    res = std::min(res*2, res+K);

  printf("%d\n", res);
}