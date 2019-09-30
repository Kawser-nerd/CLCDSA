#include <stdio.h>

int main (void){
  int a,b,c,s;
  scanf("%d %d %d",&a,&b,&c);
  s=a*b/2;
  printf("%d",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&c);
   ^