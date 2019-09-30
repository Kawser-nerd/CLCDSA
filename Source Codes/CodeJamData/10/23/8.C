#include <cstdio>
#include <iostream>
#include <gmp.h>

using namespace std;

long long dp[521][521];

int choose(int n, int k) {
    mpz_t res;
    mpz_init(res);
    mpz_bin_uiui(res, n, k);
    return mpz_mod_ui(res, res, 100003); 
}

void pre_compute()
{
    dp[1][1] = 1;
    dp[2][1] = 1;
    for (int i = 3; i <= 510; i ++) {
        dp[i][i] = 0;
        for (int j = i -1; j >= 2; j --) {
            dp[i][j] = 0;
            for (int k = 1; k < j ; k ++)
               dp[i][j] = (dp[i][j] + (dp[j][k] * choose((i - j -1), j -k-1)) % 100003) % 100003;
        }
        dp[i][1] = 1;
    }
}
int main()
{
    int T;
    int N;
    pre_compute();
    scanf("%d", &T);
    

    for (int cc = 1; cc <= T; cc ++) {
        scanf("%d", &N);
        long long ans = 0;
        for (int i = 1; i < N; i ++) {
            ans = (ans + dp[N][i]) % 100003;
        }
        printf("Case #%d: %lld\n", cc, ans);
    }
    return 0;
}
