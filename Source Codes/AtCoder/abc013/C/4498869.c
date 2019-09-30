#include <stdio.h>
#define max(a, b) (a>b ? a:b)
#define min(a, b) (a<b ? a:b)
// ????
long Eat (long N, long H, long A, long B, long C, long D, long E) {
    long money = 10000000000000;
    // ??
    for (long normal = 0; normal <= N; normal++) {
        long fasting = N-normal; // ????
        long satisfy = H+B*normal;   // ???
        long simple = max((E*fasting+D+E-satisfy)/(D+E), 0);
        money = min(money, A*normal+C*simple);
    }
    return money;
}

int main(int argc, char const *argv[]) {
    // ??
    long N, H;
    long A, B, C, D, E;
    // ??
    scanf("%ld %ld", &N, &H);
    scanf("%ld %ld %ld %ld %ld", &A, &B, &C, &D, &E);
    // ??
    long ans = Eat(N, H, A, B, C, D, E);
    // ??pr
    printf("%ld\n", ans );
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld", &N, &H);
     ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld %ld %ld", &A, &B, &C, &D, &E);
     ^