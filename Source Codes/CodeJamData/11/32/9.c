#include <stdio.h>
#include <stdlib.h>

int intcmp(const void *v1, const void *v2) {
  return (*(int *)v2 - *(int *)v1);
}
int a[1000001];
int main() {
  int t, l, n, c, i, j, k;
  unsigned long long h;
  scanf("%d", &t);
  for (i = 0;i < t; ++i) {
    scanf("%d %llu %d %d", &l, &h, &n, &c);
    for (j = 0;j < c; ++j) {
      scanf("%d", &a[j]);
      for (k = 1;k < 1000000; ++k) {
        int index = k*c+j;
        if (index > n) {break;}
        a[index] = a[j];
      }
    }
    unsigned long long ah = h/2;
    unsigned long long total = 0;
    for (j = 0;j < n; ++j) {
      total += a[j]*2;
      if (ah >= a[j]) {
        ah -= a[j];
        a[j] = 0;
      } else {
        a[j] -= ah;
        break;
      }
    }
    unsigned long long res = h;
    if (total <= h) {res = total;} else {
    qsort(a, n, sizeof(a[0]), intcmp);
    for (j = 0;j < n; ++j) {
      if (j < l) {
        res += a[j];
      } else {
        res += a[j]*2;
      }
    }
    }
    printf("Case #%d: ", i + 1);
    printf("%llu\n", res);
  }
  return 0;
}
