#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  int a,b,h;
  scanf("%d%d%d",&a,&b,&h);
  printf("%d",(a+b)*h/2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&h);
   ^