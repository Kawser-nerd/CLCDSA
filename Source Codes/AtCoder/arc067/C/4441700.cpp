#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const ll M = 1000000007;
ll inv[1005], fac[1005], fiv[1005];
ll dp[1005][1005]; // i??j??????????????????

ll comb(int n, int k) {
    return fac[n] * fiv[k] % M * fiv[n-k] % M;
}

ll pow_mod(ll num, ll pow) {
    ll prod = 1;
    num %= M;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % M;
        num = num * num % M;
        pow >>= 1;
    }
    return prod;
}

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    inv[1] = fac[1] = fiv[1] = inv[0] = fac[0] = fiv[0] = 1;
    for (ll i = 2; i < 1005; i++) {
        fac[i] = fac[i - 1] * i % M; // n!
        inv[i] = inv[M % i] * (M - M / i) % M; // n^-1
        fiv[i] = fiv[i - 1] * inv[i] % M; // (n!)^-1
    }

    dp[0][A] = 1;
    for (int i = 0; i <= N; i++) {
        for (int j = A; j <= B; j++) {
            (dp[i][j + 1] += dp[i][j]) %= M;

            for (int k = C; k <= D; k++) {
                // dp[i][j] -> i??j?????????
                // dp[i+k*(j+1)][j+1] -> ?????j+1??????k???
                int people = k * j;
                if (i + people > N) break;
                ll tmp = fac[people] * comb(N - i, people) % M * fiv[k] % M * pow_mod(fiv[j], k) % M;
                (dp[i + people][j + 1] += dp[i][j] * tmp % M) %= M;
            }
        }
    }

    cout << dp[N][B+1] << "\n";
    return 0;
}