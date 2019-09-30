#include <stdio.h>
#include <math.h>

int main(void){
  int X;
  scanf("%d",&X);

  X = sqrt(X);
  X = sqrt(X);
  printf("%d\n",X);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&X);
   ^