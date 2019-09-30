#include<stdio.h>

int main()
{
    long long a,num;
    int digit=1,flag=0,b,ans;
    scanf("%lld",&a);
    while(a>=10)
    {
        num=a%10;
        if(num!=9)flag=1;
        a/=10;
        digit++;
    }
    b=(int)(a);
    ans=(b-flag)+(digit-1)*9;
    printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&a);
     ^