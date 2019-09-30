#include <stdio.h>

int main(void){
  int x, a, b;
  scanf("%d %d %d", &x, &a, &b);
  a -= x;
  b -= x;
  if(a < 0) a = -a;
  if(b < 0) b = -b;
  if(a > b) printf("B\n");
  else printf("A\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &x, &a, &b);
   ^