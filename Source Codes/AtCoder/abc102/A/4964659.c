#include <stdio.h>

int main(){
	double a;
  scanf("%lf",&a);
  if((int)a%2==0) printf("%.0f\n",a);
  else printf("%.0f\n",a*2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf",&a);
   ^