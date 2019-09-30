#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int quick(const void *a, const void *b) {
  return *(long *)a - *(long *)b;
}

int main(void) {
  int n, k;
  long h[100001], ans;

  if(scanf("%d %d", &n, &k) == 1);

  for(int i = 0; i < n; i++) {
    if(scanf("%ld", &h[i]) == 1);
  }

  qsort(h, n, sizeof(long), quick);

  ans = h[n - 1] + 1;

  for(int i = 0; i < n - k + 1; i++) {
    if(h[i + k - 1] - h[i] < ans) {
      ans = h[i + k - 1] - h[i];
    }
  }

  printf("%ld", ans);

  return 0;
}