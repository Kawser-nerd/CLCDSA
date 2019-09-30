#include <stdio.h>
int main() {
long long a, b, k, l, x, y = 0;
scanf("%lld %lld %lld %lld",&a,&b,&k,&l);
x = k / l;
y = k % l;
if (b <= y * a) {
printf("%lld\n",(x + 1) * b);
} else {
printf("%lld\n",x * b + y * a);
} return 0; 
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%lld %lld %lld %lld",&a,&b,&k,&l);
 ^