#include <stdio.h>

int main(void){
  int x, t;
  scanf("%d %d", &x, &t);
  x -= t;
  if(x < 0) x = 0;
  printf("%d\n", x);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &x, &t);
   ^