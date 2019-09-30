/**
 * D - ??
 */

#include <iostream>

using namespace std;

const int MOD = 1'000'000'007;

int H, W;
int a[1002][1002];
int dp[1002][1002];

int rec(int i, int j) {

    if (dp[i][j] != 0) return dp[i][j];

    int ret = 1;

    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (abs(k + l) == 1 && a[i + k][j + l] > a[i][j]) {
                ret += rec(i + k, j + l);
                ret %= MOD;
            }
        }
    }

    return dp[i][j] = ret;
}

int main() {

    cin >> H >> W;

    fill(a[0], a[1002], 0);
    fill(dp[0], dp[1002], 0);

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            ans += rec(i, j);
            ans %= MOD;
        }
    }

    cout << ans << endl;
} ./Main.cpp:37:16: warning: array index 1002 is past the end of the array (which contains 1002 elements) [-Warray-bounds]
    fill(a[0], a[1002], 0);
               ^ ~~~~
./Main.cpp:12:1: note: array 'a' declared here
int a[1002][1002];
^
./Main.cpp:38:17: warning: array index 1002 is past the end of the array (which contains 1002 elements) [-Warray-bounds]
    fill(dp[0], dp[1002], 0);
                ^  ~~~~
./Main.cpp:13:1: note: array 'dp' declared here
int dp[1002][1002];
^
2 warnings generated.