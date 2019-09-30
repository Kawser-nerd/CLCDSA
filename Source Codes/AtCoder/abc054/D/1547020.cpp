//
// D - Mixing Experiment
//

#include <iostream>

using namespace std;

const int INF = 1 << 29;
int dp[41][401][401];

int main() {

    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;

    fill(dp[0][0], dp[41][0], INF);
    dp[0][0][0] = 0;
    int Ta = 0, Tb = 0;

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = 0; j <= Ta; j++) {
            for (int k = 0; k <= Tb; k++) {
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
                dp[i + 1][j + a][k + b] = min(dp[i + 1][j + a][k + b], dp[i][j][k] + c);
            }
        }
        Ta += a;
        Tb += b;
    }

    int ans = INF;

    for (int i = Ma, j = Mb; i <= Ta && j <= Tb; i += Ma, j += Mb) {
        ans = min(ans, dp[N][i][j]);
    }

    cout << (ans != INF ? ans : -1) << endl;
}