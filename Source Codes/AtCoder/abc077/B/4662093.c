#include <stdio.h>
#include <math.h>
int main(void){
    long long int n;
    double k;
    scanf("%lld",&n);
    k=sqrt((double)n);
    printf("%lld\n",(long long int)(floor(k)*floor(k)));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^