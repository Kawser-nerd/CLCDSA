#include <stdio.h>

void solv(int n) {
  int i, j, c[501], s[501], f[501], k;
  int sec;

  c[0] = s[0] = f[0] = 0;
  for (i = 1; i <= n - 1; i++) {
    scanf("%d %d %d", c + i, s + i, f + i);
  }

  for (k = 1; k <= n; k ++) {
    sec = 0;
    for (i = k; i < n; i++) {
      for (j = 0; sec > s[i] + f[i] * j; j++) {}
      sec = s[i] + f[i] * j + c[i];
    }
    printf("%d\n", sec);
  }
}

int main(int argc, char **argv) {
  int n;

  while (scanf("%d\n", &n) != EOF) {
    solv(n);
  }

  return 0;
} ./Main.c: In function ‘solv’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", c + i, s + i, f + i);
     ^