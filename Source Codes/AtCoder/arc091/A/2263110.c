#include<stdio.h>
int main()
{
   long long int n,x,a,b;
    scanf("%lld %lld",&a,&b);
    n=a*b;
    x=2*a+2*b-4;
    if(n>x)
    printf("%lld",n-x);
    else
    printf("%lld",x-n);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&a,&b);
     ^