#include<stdio.h>
int main(void){

  double i;

  scanf("%lf", &i);
  printf("%f\n", 9.0 / 5.0 * i + 32);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf", &i);
   ^