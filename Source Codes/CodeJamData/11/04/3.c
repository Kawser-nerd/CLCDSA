#include <stdio.h>

int main(void) {
  int T, tt;
  scanf("%d", &T);
  for (tt = 1; tt <= T; tt++) {
    int N, i, m = 0;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
      int n;
      scanf("%d", &n);
      if (n == i) m++;
    }
    printf("Case #%d: %.5f\n", tt, (float)(N - m));
  }
  return 0;
}
