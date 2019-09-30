#include <stdio.h>

int check(int n, int *h) {
  int i;

  for (i = 0; i < n ; i++) {
    if (h[i] != 0) {
      return 0;
    }
  }

  return 1;
}

int solv(int n) {
  int i, j, h[100];

  for (i = 0; i < n; i++) {
    scanf("%d", h + i);
  }

  for (i = 0; check(n, h) == 0; i++) {
    for (j = 0; j < n && h[j] == 0; j++) {}
    // j ?????????
    for (; j < n && h[j] != 0; j++) {
      h[j]--;
    }
  }

  return i;
}

int main(int argc, char **argv) {
  int n;

  while (scanf("%d\n", &n) != EOF) {
    printf("%d\n", solv(n));
  }

  return 0;
} ./Main.c: In function ‘solv’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", h + i);
     ^