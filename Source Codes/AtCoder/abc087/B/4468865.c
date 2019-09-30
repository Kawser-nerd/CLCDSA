#include <stdio.h>

// a: 500, b: 100, c: 50
int solv(int a, int b, int c, int x) {
  int i, j, k, count = 0, y;

  for (i = 0; i <= a; i++) {
    for (j = 0; j <= b; j++) {
      y = i * 500 + j * 100;
      if (x - y < 0) {
        break;
      }
      k = (x - y) / 50;
      if (k <= c) {
        count++;
      }
    }
  }

  return count;
}

int main(int argc, char **argv) {
  int a, b, c, x;

  while (scanf("%d %d %d %d", &a, &b, &c, &x) != EOF) {
    printf("%d\n", solv(a, b, c, x));
  }

  return 0;
}