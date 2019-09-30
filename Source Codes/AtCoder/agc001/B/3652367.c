#include <stdio.h>
long long gcd(long long a, long long b){return (a<b?a:b)==0?(a>b?a:b):gcd((a<b?a:b),(a>b?a:b)%(a<b?a:b));}
int main(void){
    long long n,x;
    scanf("%lld%lld",&n,&x);
    printf("%lld\n",3*(n-gcd(n,x)));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&x);
     ^