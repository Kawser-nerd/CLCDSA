#include <stdio.h>
int main(void){
    long long int A, B, ans = 0;
    if (scanf("%lld %lld", &A, &B) == -1) return 0;
    if (A % 2 == 1) {
        ans ^= A;
        for (int i = 0; i < (B - A) % 4; i++) ans ^= B - i;
    }
    else {
        for (int i = 0; i < (B - A + 1) % 4; i++) ans ^= B - i;
    }
    printf("%lld\n", ans);
    return 0;
}