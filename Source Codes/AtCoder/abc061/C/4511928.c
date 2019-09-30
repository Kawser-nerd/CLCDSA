#include<stdio.h>
int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long i, a, b;
    long long p[100005] = {};
    for (i = 0; i < n; i++)
    {
        scanf("%lld %lld", &a, &b);
        p[a] += b;
    }
    i = 0;
    while (k > 0)
    {
        k -= p[i];
        i++;
    }
    i--;
    printf("%lld\n", i);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld", &n, &k);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld %lld", &a, &b);
         ^