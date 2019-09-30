#include <stdio.h>
#include <string.h>
int main() {
  int X;
  int Y;
  scanf("%d %d", &X, &Y);
  int fare = X + Y/2;
  printf("%d\n", fare);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &X, &Y);
   ^