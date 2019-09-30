#include<stdio.h>
main() {
  int t, c;
  scanf("%d", &t);
  for (c = 1; c <= t; c++) {
    long long b, m;
    scanf("%lld %lld", &b, &m);
    printf("Case #%d:", c);
    if (m > (1ll << (b-1))) {
      puts("IMPOSSIBLE");
      continue;
    } else {
      puts("POSSIBLE");
    }
    m--;
    int i, j;
    for (i = 0; i < b; i++) {
      for (j = 0; j < b; j++) {
        int conn = 0;
        if (0 < i && i < b && i < j) {
          conn = 1;
        }
        if (i == 0 && j == b-1) {
          conn = 1;
        }
        if (i == 0 && i < j && ((1ll << (b-2-j))&m) > 0) {
          conn = 1;
        }
        printf("%d", conn);
      }
      puts("");
    }
  }
}
