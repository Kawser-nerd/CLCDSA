#include <stdio.h>

int main() {
  int X, Y, ans;
  scanf("%d %d", &X, &Y);
  ans = X + Y / 2;
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &X, &Y);
   ^