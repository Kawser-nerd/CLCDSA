#include <stdio.h>
int main()
{  long long a,b,c,k,i;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
    if(k%2==1)printf("%lld",b-a);else printf("%lld",a-b);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
     ^