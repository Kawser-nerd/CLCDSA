#include <stdio.h>

int main(void){
  int X, Y, Z;
  scanf("%d", &X);
  scanf("%d", &Y);
  Z = X+Y/2;
  printf("%d", Z);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &X);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &Y);
   ^