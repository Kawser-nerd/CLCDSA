#include <stdio.h>
#include <math.h>

int main(void){
  double n;
  scanf("%lf", &n);
  
  printf("%.0f\n", sqrt(sqrt(n)));
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf", &n);
   ^