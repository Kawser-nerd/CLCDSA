#include <stdio.h>
#include <math.h>

int main(void){
  double n, m;
  scanf("%lf %lf", &n, &m);
  double nx, mx;
  nx = n * 30 + m / 2;
  mx = m * 6;
  double ans = fabs(mx - nx);
  
  while(360 < ans) ans -= 360;
  
  printf("%lf\n", fmin(ans, 360 - ans));
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf", &n, &m);
   ^