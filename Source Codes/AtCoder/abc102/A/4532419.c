#include <stdio.h>

int main(){
  int n;scanf("%d",&n);
  n%2==0?printf("%d",n):printf("%d",2*n);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   int n;scanf("%d",&n);
         ^