#include <cstdio>

int main() {
  int X;
  scanf("%d", &X);

  int res = 0;
  int sum = 0;
  for (int t = 1; sum < X; ++t) {
    sum += t;
    res = t;
  }
  printf("%d\n", res);
}