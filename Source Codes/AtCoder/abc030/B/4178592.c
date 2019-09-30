#include<stdio.h>
#include<math.h>

int main(){
  float n, m, a, h;
  
  scanf("%f %f", &n, &m);
  if(n > 12){
    n = n -12;
  }
  
  h = 360*n/12 + 30*m/60;
  m = 360*m/60;
  
  a = fabs(m - h);
  
  if(a > 180){
    a = 360 - a;
  }
  
  printf("%f\n", a);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%f %f", &n, &m);
   ^