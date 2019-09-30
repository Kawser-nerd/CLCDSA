#include <stdio.h>
int main(void){
    long long int n;
    scanf("%lld",&n);
    printf("%lld\n",2*n);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^