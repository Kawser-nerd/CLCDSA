#include<stdio.h>
int main()
{
    unsigned long long int q, h, s, d;
    scanf("%lld %lld %lld %lld", &q, &h, &s, &d);
    unsigned long long int n;
    scanf("%lld", &n);
    unsigned long long int ans = 0;
    unsigned long long int min = d;
    if (2 * s < min)min = 2 * s;
    if (4 * h < min)min = 4 * h;
    if (8 * q < min)min = 8 * q;
    ans += min * (n / 2);
    n %= 2;
    min = s;
    if (2 * h < min)min = 2 * h;
    if (4 * q < min)min = 4 * q;
    ans += min * n;
    printf("%lld\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld %lld", &q, &h, &s, &d);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &n);
     ^