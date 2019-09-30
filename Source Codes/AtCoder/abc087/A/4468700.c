#include <stdio.h>

int main(int argc, char **argv) {
  int x, a, b, n;

  while (scanf("%d %d %d", &x, &a, &b) != EOF) {
    n = (x - a) / b;
    printf("%d\n", x - a - b * n);
  }

  return 0;
}