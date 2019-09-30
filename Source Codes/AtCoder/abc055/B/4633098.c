#include <stdio.h>
int main(void){
    long long int n,v=1;
    scanf("%lld",&n);
    while(n!=0){
        v=v*n%1000000007;
        n--;
    }
    printf("%lld\n",v);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^