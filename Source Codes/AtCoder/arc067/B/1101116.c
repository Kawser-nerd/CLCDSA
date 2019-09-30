#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i, N;
    long long A, B, T, X1, X2;

    scanf("%d%lld%lld", &N, &A, &B);
    T = 0;
    scanf("%lld", &X1);
    for (i=1;i<N;i++) {
        scanf("%lld", &X2);
        if (A*(X2-X1) < B) T += A*(X2-X1);
        else T += B;
        X1 = X2;
    }

    printf("%lld\n", T);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%lld%lld", &N, &A, &B);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &X1);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld", &X2);
         ^