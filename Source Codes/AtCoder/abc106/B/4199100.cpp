#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  int res = 0;
  for (int i = 1; i <= N; i += 2) {
    int div = 0;
    for (int j = 1; j <= i; ++j)
      if (i % j == 0) ++div;
    if (div == 8) ++res;
  }
  printf("%d\n", res);
}