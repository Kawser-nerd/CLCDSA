#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  int res = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    scanf("%d", &a);

    res += __builtin_ctz(a);
  }
  printf("%d\n", res);
}