#include <stdio.h>


int main()
{
    long long a, b;
    char c;
    scanf("%lld %c %lld",&a, &c, &b);
    if(c=='+'){
        printf("%lld", a+b);
    }
    else if(c=='-'){
        printf("%lld", a-b);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %c %lld",&a, &c, &b);
     ^