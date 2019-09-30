#include<stdio.h>
 
int main()
{
  double a,b;
  scanf("%lf%lf",&a,&b);
  printf("%.10f",a/b);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf%lf",&a,&b);
   ^