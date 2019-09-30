#include <stdio.h>
int main(void){
  int a,b,a2,b2;
  scanf("%d%d",&a,&b);
  a2=b;
  b2=a;
  printf("%d %d",a2,b2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^