#include <stdio.h>
int main(){
  int k,a;
  scanf("%d",&k);
  a=k/2;
  printf("%d",(k-a)*a);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^