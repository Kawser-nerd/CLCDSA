#include <stdio.h>

int main() {
  int X, Y, Z;
  scanf("%d %d %d", &X, &Y, &Z);
  int area = X * Y / 2;
  printf("%d\n", area);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &X, &Y, &Z);
   ^