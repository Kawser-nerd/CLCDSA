#include<stdio.h>
long long Dc(long long a)
{
    if(a<0) return -a;
    else    return a;
}
int main(void)
{
    long long n,i,x,num=0,num1=0,num2;
    scanf("%lld",&n);
    long long a[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        num+=a[i];
    }
    x=Dc(num-2*a[0]);
    for(i=0;i<n-1;i++)
    {
        num1+=a[i];
        num2=num-num1;
        if(Dc(num1-num2)<x)    x=Dc(num1-num2);
    }
        printf("%lld\n",x);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^