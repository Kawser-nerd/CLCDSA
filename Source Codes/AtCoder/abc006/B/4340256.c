#include <stdio.h>
#define N_max 1000001
#define Mod 10007
long Tribonatti_mod[N_max] = {0};

long Mod_Tribonatti (int N) {
    if (N==1 || N==2) {
        Tribonatti_mod[N] = 0;
        return Tribonatti_mod[N];
    } else if (N==3) {
        Tribonatti_mod[N] = 1;
        return Tribonatti_mod[N];
    } else {
        if (Tribonatti_mod[N] != 0) {
            return Tribonatti_mod[N]%Mod;
        } else {
            Tribonatti_mod[N] = Mod_Tribonatti(N-1)+Mod_Tribonatti(N-2)+Mod_Tribonatti(N-3);
            return Tribonatti_mod[N]%Mod;
        }
    }
}


int main(int argc, char const *argv[]) {
    // ??
    long N;
    // ??
    scanf("%ld", &N );
    // ??
    printf("%ld\n", Mod_Tribonatti(N));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &N );
     ^