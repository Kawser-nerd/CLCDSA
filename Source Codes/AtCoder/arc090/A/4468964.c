#include <stdio.h>

int solv(int n) {
  int i, a1[101], a2[101], max, res;

  for (i = 0; i < n; i++) {
    scanf("%d", a1 + i);
  }
  for (i = 0; i < n; i++) {
    scanf("%d", a2 + i);
  }

  for (i = 1; i < n; i++) {
    a1[i] += a1[i - 1];
    a2[n - i - 1] += a2[n - i];
  }

  res = 0;
  max = 0;
  for (i = 0; i < n; i++) {
    if (max < a1[i] + a2[i]) {
      res = i;
      max = a1[i] + a2[i];
    }
  }

  return max;
}

int main(int argc, char **argv) {
  int n;

  while (scanf("%d", &n) != EOF) {
    printf("%d\n", solv(n));
  }

  return 0;
} ./Main.c: In function ‘solv’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", a1 + i);
     ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", a2 + i);
     ^