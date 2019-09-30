#include <stdio.h>
int main(){
  int a,b,x;
  scanf("%d%d",&a,&b);
  x=(a+b+1)/2;
  printf("%d",x);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^