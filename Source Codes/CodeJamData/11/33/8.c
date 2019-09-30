#include <stdio.h>
#include <stdlib.h>

int main() {
  int a[101];
  int t, l, n, h, i, j, k;
  scanf("%d", &t);
  for (i = 0;i < t; ++i) {
    scanf("%d %d %d", &n, &l, &h);
    for (j = 0;j < n; ++j) {
      scanf("%d", &a[j]);
    }
    int res = -1;
    for (j = l;j <= h; ++j) {
      int flag = 1;
      for (k = 0;k < n; ++k) {
        if (a[k] % j && j % a[k]) {
          flag = 0;
          break;
        }
      }
      if (flag) {res = j; break;}
    }
    printf("Case #%d: ", i + 1);
    if (res == -1) {
      printf("NO\n");
    } else { 
      printf("%d\n", res);
    }
  }
  return 0;
}
