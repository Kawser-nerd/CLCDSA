#include <stdio.h>

const long long MAX = 2e12;

int main(void)
{
    long long a;
    long long k;
    long long d;

    scanf("%lld %lld", &a, &k);
    if (k == 0){
        printf("%lld\n", MAX - a);
    }
    else {
        d = 0;
        // printf("%lld\n", a);
        while (a < MAX){
            a += a * k + 1;
            ++d;
            // printf(" %lld\n", a);
        }
        printf("%lld\n", d);
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld", &a, &k);
     ^