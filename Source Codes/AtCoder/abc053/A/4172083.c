#include <stdio.h>
int main(void){
  int n;
  scanf("%d",&n);
  printf("%s",n<1200?"ABC":"ARC");
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^