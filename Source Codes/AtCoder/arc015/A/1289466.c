#include <stdio.h>
int main(){
double n;
scanf("%lf", &n);
printf("%lf\n", (1.8*n)+32);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%lf", &n);
 ^