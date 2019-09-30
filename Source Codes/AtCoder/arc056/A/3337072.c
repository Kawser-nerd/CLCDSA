#include <stdio.h>
int main(void){
    long long a,b,k,l;
    scanf("%lld%lld%lld%lld",&a,&b,&k,&l);
    if ((k+l-1)/l*b<(k/l)*b+(k%l)*a){
        printf("%lld\n",(k+l-1)/l*b);
    } else {
        printf("%lld\n",(k/l)*b+(k%l)*a);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld%lld",&a,&b,&k,&l);
     ^