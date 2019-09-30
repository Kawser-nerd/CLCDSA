#include<stdio.h>
int main(){
  double h,b;
  scanf("%lf %lf",&h,&b);
  printf("%f\n",h*h*b/10000);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf",&h,&b);
   ^