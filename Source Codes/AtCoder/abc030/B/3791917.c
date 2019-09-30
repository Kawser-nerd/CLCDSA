#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  double n, m;

  scanf("%lf%lf", &n, &m);

  if(n >= 12){
    n -= 12;
  }

  if(fabs((30 * n) - ((m * 11) / 2)) <= 180){
    printf("%.4lf\n", fabs((30 * n) - ((m * 11) / 2)));
  }else{
    printf("%.4lf\n", 360 - fabs((30 * n) - ((m * 11) / 2)));
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf%lf", &n, &m);
   ^