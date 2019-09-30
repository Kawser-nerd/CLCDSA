#include <stdio.h>
#include <math.h>

int main(void){
  double xa, ya, xb, yb, xc, yc;
  double ans;
  scanf("%lf %lf %lf %lf %lf %lf",&xa, &ya, &xb, &yb, &xc, &yc);
  xa -= xc;
  ya -= yc;
  xb -= xc;
  yb -= yc;
  ans = fabs(xa*yb-xb*ya)/2;
  printf("%lf\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf %lf %lf %lf %lf",&xa, &ya, &xb, &yb, &xc, &yc);
   ^