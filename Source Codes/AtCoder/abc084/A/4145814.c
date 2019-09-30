#include <stdio.h>

int main(void){
  int m;
  scanf("%d", &m);
  m -= 24;
  m = -m;
  printf("%d\n", m + 24);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &m);
   ^