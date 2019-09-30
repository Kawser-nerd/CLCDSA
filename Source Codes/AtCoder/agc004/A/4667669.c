#include <stdio.h>
#include <limits.h>
int main(void){
    long long int a,b,c,min=LLONG_MAX;
    scanf("%lld%lld%lld",&a,&b,&c);
    if((a%2)*b*c<min) min=(a%2)*b*c;
    if((b%2)*c*a<min) min=(b%2)*c*a;
    if((c%2)*a*b<min) min=(c%2)*a*b;
    printf("%lld\n",min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld",&a,&b,&c);
     ^