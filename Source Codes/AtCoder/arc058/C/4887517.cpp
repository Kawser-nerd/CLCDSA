#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

ll dp[50][1 << 18];
// i??????????j??XYZ??????????

ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1;
    num %= mod;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % mod;
        num = num * num % mod;
        pow >>= 1;
    }
    return prod;
}

int main() {
    int N, C[3];
    cin >> N >> C[0] >> C[1] >> C[2];
    int sm = C[0] + C[1] + C[2] - 1;
    int mx = 1 << sm;

    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < mx; j++) {
            if (dp[i][j] == 0) continue;

            vector <int> vec;
            int tmp = 1;
            for (int k = 0; k < sm; k++) {
                if (j & (1 << k)) {
                    vec.push_back(tmp);
                    tmp = 1;
                } else {
                    tmp++;
                }
            }

            for (int k = 1; k <= 10; k++) {
                if (k <= C[2]) {
                    int idx = 2;
                    int tmp = C[2] - k;
                    if (tmp == 0) {
                        idx--;
                        tmp = C[idx];
                    }

                    bool ng = false;
                    for (int x : vec) {
                        if (tmp - x > 0) {
                            tmp -= x;
                        } else if (tmp == x) {
                            idx--;
                            if (idx == -1) {
                                ng = true;
                                break;
                            } else {
                                tmp = C[idx];
                            }
                        } else {
                            break;
                        }
                    }

                    if (ng) continue;
                }

                ll nxt = (j * 2 + 1) * pow_mod(2, k-1, mx) % mx;

                dp[i+1][nxt] += dp[i][j];
                dp[i+1][nxt] %= MOD;
            }
        }
    }

    ll ans = pow_mod(10, N, MOD);
    for (int j = 0; j < mx; j++) {
        ans += MOD - dp[N][j];
        ans %= MOD;
    }

    cout << ans << "\n";
    return 0;
}