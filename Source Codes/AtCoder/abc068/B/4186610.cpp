#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  int res = 1;
  int count = 0;
  for (int i = 2; i <= N; ++i) {
    int cur = 0;
    for (int j = i; j % 2 == 0; j /= 2)
      ++cur;

    if (cur > count) {
      res = i;
      count = cur;
    }
  }
  printf("%d\n", res);
}