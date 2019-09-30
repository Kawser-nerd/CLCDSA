#include <stdio.h>
#include <math.h>
int main(void){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  int d=fmin(a,b);
  printf("%d",c/d);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^