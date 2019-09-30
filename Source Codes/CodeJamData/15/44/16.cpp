#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const long long MOD = 1000000007;

long long dp[105][2][13];

long long lcm[13][13];

long long inv[13];

long long inverse(long long i) {
    return i == 1 ? 1 : (long long)(MOD - MOD / i) * inverse(MOD % i) % MOD;
}
int main() {
    for (long long i = 1; i <= 12; ++i) {
        for (long long j = 1; j <= 12; ++j) {
            lcm[i][j] = i * j / __gcd(i, j);
        }
        inv[i] = inverse(i);
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int r, c;
        scanf("%d%d", &r, &c);
        memset(dp, 0, sizeof(dp));
        dp[0][0][1] = 1;
        dp[0][1][1] = 1;
        for (long long i = 0; i < r; ++i) {
            for (long long j = 1; j <= 12; ++j) {
                //3 - ring
                (dp[i + 2][1][lcm[j][1]] += dp[i][0][j]) % MOD;
                //2 - ring
                (dp[i + 1][0][lcm[j][1]] += dp[i][1][j]) % MOD;
                //1 - 2 ring
                if (c % 3 == 0) {
                    (dp[i + 2][0][lcm[j][3]] += (long long)dp[i][1][j] * 3 % MOD) %= MOD;
                }
                if (c % 6 == 0) {
                    (dp[i + 2][0][lcm[j][6]] += (long long)dp[i][1][j] * 6 % MOD) %= MOD;
                }
                if (c % 4 == 0) {
                    (dp[i + 3][0][lcm[j][4]] += (long long)dp[i][1][j] * 4 % MOD) %= MOD;
                }
            }
        }
        long long sum = 0;
        for (long long i = 0; i < 2; ++i) {
            for (long long j = 1; j <= 12; ++j) {
                //cout << i << ' ' << j << ' ' << dp[r][i][j] << endl;
                (sum += (long long)dp[r][i][j] * inv[j] % MOD) %= MOD;
            }
        }
        static int id = 0;

        printf ("Case #%d: %d\n", ++id, (int)sum);
    }
    return 0;
}
