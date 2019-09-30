#include <stdio.h>
int main(void){
    long long int a,b,c,d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    printf("%lld\n",a*b>c*d?a*b:c*d);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
     ^