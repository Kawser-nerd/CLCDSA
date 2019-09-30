#include <stdio.h>
#include <math.h>

int main(void){
  double n,m;
  scanf("%lf%lf",&n,&m);

  if(n > 12) n -= 12;
  n += m/60;
  n *= 5;

  double ans = fabs(n-m)*6;
  if(ans > 180) ans = 360-ans;
  printf("%lf\n",ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf%lf",&n,&m);
   ^