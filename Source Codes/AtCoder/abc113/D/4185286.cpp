#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    K--;

    using ll = long long;

    const ll mod = 1000000007;

    ll dp[101][9] = {0};

    dp[0][0] = 1;

    for (int i = 0; i < H; i++) {
        for (unsigned j = 0; j < (1 << (W - 1)); j++) {
            bool ok = true;

            for (int k = 0; k < W - 2; k++) {    
                if ((j >> k & 1) && (j >> (k + 1) & 1)) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                for (int k = 0; k < W; k++) {
                    if (k < W - 1 && j >> k & 1) {
                        dp[i + 1][k + 1] = (dp[i + 1][k + 1] + dp[i][k]) % mod;
                    } else if (k > 0 && j >> (k - 1) & 1) {
                        dp[i + 1][k - 1] = (dp[i + 1][k - 1] + dp[i][k]) % mod;
                    } else {
                        dp[i + 1][k] = (dp[i + 1][k] + dp[i][k]) % mod;
                    }
                }
            }
        }
    }

    cout << dp[H][K] << endl;
}