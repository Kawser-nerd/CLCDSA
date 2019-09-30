#include<stdio.h>

int main()
{
    long long n, m;
    scanf("%lld%lld", &n, &m);
    if(2*n>=m)
        printf("%lld\n", m/2);
    else
    {
        long long s=0;
        s+=n;
        m-=2*n;
        s+=m/4;
        printf("%lld\n", s);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld", &n, &m);
     ^