#include<stdio.h>
long long solve(long long x,long long n)
{
    long long sjx;
    if(n%x==0)
        return n*2-x;
    sjx = n/x*x*2+solve(n%x,x);
    return sjx;
}
int main()
{
    long long n,x;
    long long sjx;
    scanf("%lld%lld",&n,&x);
    sjx = solve(x,n-x)+n;
    printf("%lld\n",sjx);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&x);
     ^