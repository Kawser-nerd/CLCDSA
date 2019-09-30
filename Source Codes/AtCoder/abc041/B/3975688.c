#include <stdio.h>

int main()
{
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    long long ans=a*b%1000000007;
    ans*=c;
    ans%=1000000007;
    printf("%lld",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld",&a,&b,&c);
     ^