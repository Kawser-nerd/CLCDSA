#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  int d=a*b*2+b*c*2+a*c*2;
  printf("%d",d);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^