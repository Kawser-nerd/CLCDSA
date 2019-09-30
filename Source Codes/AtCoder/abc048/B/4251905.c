#include <stdio.h>
long long func(long long n,long long x){
    if(n>=0)return n/x+1;
    return 0;
}
int main()
{
    long long a,b,x;
    scanf("%lld%lld%lld",&a,&b,&x);
    printf("%lld",func(b,x)-func(a-1,x));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld",&a,&b,&x);
     ^