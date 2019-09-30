#include<stdio.h>
int main(){
  double n,m;
  scanf("%lf%lf",&n,&m);
  n=fabs((n-12*(n>12)+m/60)*5-m)*6;
  printf("%lf\n",n>180?360-n:n);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: implicit declaration of function ‘fabs’ [-Wimplicit-function-declaration]
   n=fabs((n-12*(n>12)+m/60)*5-m)*6;
     ^
./Main.c:5:5: warning: incompatible implicit declaration of built-in function ‘fabs’
./Main.c:5:5: note: include ‘<math.h>’ or provide a declaration of ‘fabs’
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf%lf",&n,&m);
   ^