#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
// ?????
long lFactrial (int n, long Mod, long *factrial) {
    long ans;
    if (n == 0) {
        return 1;;
    }
    ans = (n*factrial[n-1])%Mod;
    return ans;
}
// ??????
long modlPow (long n, long m, long Mod) {
    long ans = 1;
    while (m) {
        if (m&1) {
            ans = (ans*n)%Mod;
        }
        m = m >> 1;
        n = (n*n)%Mod;
    }
    return ans;
}
// ?????
long Inverse (long x, long Mod, long *factrial) {
    return modlPow(factrial[x], (Mod-2), Mod);
}

// nHk???
void  calc_nHk (int n, int k) {
    // ??
    clock_t start, end;
    start = clock();
    long Mod = lPow(10, 9)+7;
    long nHk;
    int N = n+k-1;
    long *factrial;
    factrial = (long *)malloc(sizeof(long)*(N+1));
    // ???????
    factrial[0] = 1;
    for (size_t i = 1; i <= N; i++) {
        factrial[i] = lFactrial(i, Mod, factrial);
    }
    // nHk???
    nHk = factrial[n+k-1]*Inverse(n-1, Mod, factrial)%Mod*Inverse(k, Mod, factrial)%Mod;
    // ??
    printf("%ld\n", nHk);
    end = clock();
    //printf("%.4f???????\n",10*(double)(end-start)/CLOCKS_PER_SEC);
    // ?????
    free(factrial);
}

// ???
int main(int argc, char const *argv[]) {
    // ??
    int n, k;
    // ??
    scanf("%d %d", &n, &k);
    // ??
    calc_nHk(n, k);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:73:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &k);
     ^