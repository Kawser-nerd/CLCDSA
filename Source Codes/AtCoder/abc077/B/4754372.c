#include <stdio.h>

int main(){
  double N,i = 0;
  scanf("%lf",&N);
  for (i=0;i<100000;i++){
    if(N < i*i) break;
  }
  printf("%.0f\n",(i-1)*(i-1));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf",&N);
   ^