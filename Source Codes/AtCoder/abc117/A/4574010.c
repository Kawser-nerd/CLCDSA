#include<stdio.h>

int main(){
  double time,x;
  scanf("%lf %lf",&time,&x);
  printf("%lf\n",time/x);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf",&time,&x);
   ^