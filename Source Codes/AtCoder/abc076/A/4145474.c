#include <stdio.h>

int main(void){
  int r, g;
  scanf("%d" , &r);
  scanf("%d" , &g);
  g = 2 * g - r;
  printf("%d\n", g);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d" , &r);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d" , &g);
   ^