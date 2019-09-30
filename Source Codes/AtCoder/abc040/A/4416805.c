#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  int n,x;
  scanf("%d%d",&n,&x);
  int d=fmin(n-x,x-1);
  printf("%d",d);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^