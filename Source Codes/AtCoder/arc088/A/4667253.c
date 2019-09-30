#include <stdio.h>

int main() {
    unsigned long long X, Y;
    unsigned long long res = 0;

    scanf ("%llu%llu", &X, &Y);
    for (unsigned long long i = X; i<= Y; i+=i){
        res++;
    }

    printf("%llu", res);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%llu%llu", &X, &Y);
     ^