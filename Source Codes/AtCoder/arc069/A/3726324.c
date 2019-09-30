#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long m, n, k;

    scanf("%lld%lld", &m, &n);

    if(2*m<n)
        k = (2*m+n)/4;
    else if(2*m==n)
        k = m;
    else
        k = n/2;

    printf("%lld\n", k);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld", &m, &n);
     ^