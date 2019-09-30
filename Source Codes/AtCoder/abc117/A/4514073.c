#include <stdio.h>
#include <string.h>
int main() {
  double t;
  double x;
  scanf("%lf %lf",&t,&x);
  double ans = t/x;
  printf("%lf\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf",&t,&x);
   ^