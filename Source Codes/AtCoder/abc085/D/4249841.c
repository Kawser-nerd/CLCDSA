#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int solv(int n, int h) {
  int i, a, amax = 0;
  int *b, *p;

  b = (int *)malloc(sizeof (int) * n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a, b + i);
    if (amax < a) {
      amax = a;
    }
  }
  b[i] = 0; // ??
  qsort(b, n, sizeof (int), compare);

  for (i = 0, p = b; h > 0 && amax < *p; i++, p++) {
    h -= *p;
  }
  if (h > 0) {
    i += (h - 1) / amax + 1;
  }

  free(b);

  return i;
}

int main(int argc, char **argv) {
  int n, h;

  while (scanf("%d %d", &n, &h) != EOF) {
    printf("%d\n", solv(n, h));
  }

  return 0;
} ./Main.c: In function ‘solv’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a, b + i);
     ^