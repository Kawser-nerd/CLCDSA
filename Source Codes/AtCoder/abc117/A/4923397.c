#include <stdio.h>

int main(){
  int t,x;
  scanf("%d%d",&t,&x);
  double answer = (double)t / (double)x;
  printf("%lf\n",answer);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&t,&x);
   ^