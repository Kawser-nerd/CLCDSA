#include <iostream>

using namespace std;

const int KMAX = 200000 + 5;
const int N = 2000 + 5;
const int MOD = 1000000000 + 7;
const int INV2 = 500000000 + 4;

int comb[4 * N][2 * N];

void precalc_comb() {
    for (int i = 0; i < 4 * N; ++ i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i && j < 2 * N; ++ j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            if (comb[i][j] >= MOD)
                comb[i][j] -= MOD;
        }
    }
}

int K;
int A[KMAX];
int B[KMAX];

int dp[2 * N][2 * N];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin >> K;

    for (int i = 1; i <= K; ++ i)
        cin >> A[i] >> B[i];
    for (int i = 1; i <= K; ++ i)
        ++ dp[N - A[i]][N - B[i]];

    for (int i = 1; i < 2 * N; ++ i)
        for (int j = 1; j < 2 * N; ++ j) {
            dp[i][j] += dp[i][j - 1];
            if (dp[i][j] >= MOD)
                dp[i][j] -= MOD;

            dp[i][j] += dp[i - 1][j];
            if (dp[i][j] >= MOD)
                dp[i][j] -= MOD;
        }

    precalc_comb();

    int ans = 0;
    for (int i = 1; i <= K; ++ i) {
        ans += dp[N + A[i]][N + B[i]];
        if (ans >= MOD)
            ans -= MOD;
        ans -= comb[A[i] + B[i] + A[i] + B[i]][A[i] + A[i]];
        if (ans < 0)
            ans += MOD;
    }

    ans = (1LL * ans * INV2) % MOD;

    cout << ans << '\n';
    return 0;
}