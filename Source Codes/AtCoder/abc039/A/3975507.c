#include <stdio.h>
int main(void){
  int a,b,c,total=0;
  scanf("%d%d%d",&a,&b,&c);
  total+=(a*b)*2;
  total+=(b*c)*2;
  total+=(a*c)*2;
  printf("%d",total);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^