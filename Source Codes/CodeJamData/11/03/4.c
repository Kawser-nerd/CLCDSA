#include <stdio.h>

int main(void) {
  int T, tt;
  scanf("%d", &T);
  for (tt = 1; tt <= T; tt++) {
    int N, i, min, xor, sum;
    printf("Case #%d: ", tt);
    scanf("%d", &N);
    xor = min = sum = 0;
    for (i = 0; i < N; i++) {
      int c;
      scanf("%d", &c);
      xor ^= c;
      sum += c;
      if (!min || min > c) {
        min = c;
      }
    }
    if (xor) {
      printf("NO\n");
    } else {
      printf("%d\n", sum - min);
    }
  }
  return 0;
}
