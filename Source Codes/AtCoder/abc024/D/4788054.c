#include <stdio.h>

// ????
long lPow (long n, long m) {
    if (m == 0) {
        return 1;
    } else if (m == 1) {
        return n;
    } else if (m%2 == 0) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return n*lPow(n, m-1);
    }
}
// ????????
long lModPow (long n, long m, long Mod) {
    long ans = 1;
    for (; m > 0; m /= 2) {
        if (m%2 != 0) {
            ans = (ans*n)%Mod;
        }
        n = (n*n)%Mod;
    }
    return ans;
}
// r?c???
void calcRC (long A, long B, long C) {
    long Mod = lPow(10, 9) + 7;
    A%=Mod; B%=Mod; C%=Mod;
    long AB = A*B%Mod;
    long BC = B*C%Mod;
    long CA = C*A%Mod;
    long c = (BC-AB+Mod)%Mod*lModPow((AB-BC+CA+Mod), Mod-2, Mod);
    long r = (BC-CA+Mod)%Mod*lModPow((AB-BC+CA+Mod), Mod-2, Mod);
    // ??
    printf("%ld %ld\n", r%Mod, c%Mod);
}
// ???
int main(int argc, char const *argv[]) {
    // ??
    long A, B, C;
    scanf("%ld %ld %ld", &A, &B, &C);
    // ??
    calcRC(A, B, C);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld", &A, &B, &C);
     ^