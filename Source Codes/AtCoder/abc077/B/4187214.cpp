#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  int res;
  for (res = 1; res*res <= N; ++res);
  --res;
  printf("%d\n", res*res);
}