#include <stdio.h>

int main() {
  int max, x, y;
  scanf("%d %d", &x, &y);
  max = (x >= y)? x : y;
  printf("%d\n", max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &x, &y);
   ^