//
// C - ??????? / Tak and Cards
//

#include <iostream>

using namespace std;
using LL = long long;

LL dp[51][51][2501];
int xs[51];

int main() {

    int N, A;
    cin >> N >> A;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        xs[i] = x;
    }

    dp[0][0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= 2500 - xs[i]; k++) {
                dp[i + 1][j][k] += dp[i][j][k];
                dp[i + 1][j + 1][k + xs[i]] += dp[i][j][k];
            }
        }
    }

    LL ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 2500; j++) {
            if ((double) j / i == A) {
                ans += dp[N][i][j];
            }
        }
    }

    cout << ans << endl;
}