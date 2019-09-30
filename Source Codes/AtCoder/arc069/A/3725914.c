#include<stdio.h>
int main()
{
    long long m,n,sum;
    scanf("%lld%lld",&m,&n);
    if(m<=n/2)
        sum=m+(n-2*m)/4;
    else
        sum=n/2;
    printf("%lld",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&m,&n);
     ^