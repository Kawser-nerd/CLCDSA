#include<stdio.h>

int main()
{

    long long int n,a,b,d1,d2,p,sum,i;
    long long int num[100100];
    scanf("%lld %lld %lld",&n,&a,&b);
    for(i=0; i<n; i++)
    {
        scanf("%lld",&num[i]);
    }
     sum=0;
    for(i=0; i<n-1; i++)
    {
        d1=abs(num[i]-num[i+1])*a;
        d2=b;
        if(d1<d2)sum=sum+d1;
        else
            sum=sum+d2;
    }
    printf("%lld\n",sum);


    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:12: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
         d1=abs(num[i]-num[i+1])*a;
            ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld",&n,&a,&b);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&num[i]);
         ^