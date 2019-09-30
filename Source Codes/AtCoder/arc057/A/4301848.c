#include<stdio.h>
int main()
{
    unsigned long long int a, k;
    scanf("%lld %lld", &a, &k);
    if (k == 0)
        printf("%lld\n", 2000000000000 - a);
    else
    {
        unsigned long long int ans = 0;
        while (a < 2000000000000)
        {
            ans++;
            a += 1 + k * a;
        }
        printf("%ld\n", ans);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:16: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long unsigned int’ [-Wformat=]
         printf("%ld\n", ans);
                ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld", &a, &k);
     ^