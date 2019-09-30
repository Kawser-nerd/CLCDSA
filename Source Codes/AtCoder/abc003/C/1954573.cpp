/**
 * C - AtCoder?????????
 */

#include <iostream>

using namespace std;

int N, K;
double R[101];
double dp[101][101];
double ans = 0;

int main() {

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }

    sort(R, R + N);

    //
    fill(dp[0], dp[101], 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], (dp[i][j] + R[i]) / 2);
            ans = max(ans, dp[i + 1][j + 1]);
        }
    }

    cout << fixed << ans << endl;
} ./Main.cpp:25:17: warning: array index 101 is past the end of the array (which contains 101 elements) [-Warray-bounds]
    fill(dp[0], dp[101], 0);
                ^  ~~~
./Main.cpp:11:1: note: array 'dp' declared here
double dp[101][101];
^
1 warning generated.