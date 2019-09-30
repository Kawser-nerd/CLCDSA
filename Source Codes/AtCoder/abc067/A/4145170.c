#include <stdio.h>

int main(void){
  int a, b;
  scanf("%d %d" , &a, &b);
  int flag = 0;
  if(a % 3 == 0) flag = 1;
  if(b % 3 == 0) flag = 1;
  if( (a + b) % 3 == 0) flag = 1;
  if(flag) printf("Possible\n");
  else printf("Impossible\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d" , &a, &b);
   ^