#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979

int main(void){
  int A,B,C;
  scanf("%d%d%d",&A,&B,&C);

  double ok = 100000,ng = 0;
  double mid;
  int cnt = 0;
  while(cnt <= 1000){
    mid = (ok+ng)/2;
    if(A*mid+B*sin(C*mid*PI) >= 100) ok = mid;
    else ng = mid;
    cnt++;
  }

  printf("%.14lf\n",ok);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&A,&B,&C);
   ^