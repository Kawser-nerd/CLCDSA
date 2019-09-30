#include <stdio.h>
int main()
{
    long long int n,m;
    scanf("%lld%lld",&n,&m);
    if(2*n<=m)
    {
        printf("%lld",n+(m-2*n)/4);
    }
    else
    {
        printf("%lld",m/2);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&m);
     ^