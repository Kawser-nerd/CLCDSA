#include<iostream>
#include<vector>
using namespace std;

int main() {
    int w, n, k;
    cin >> w >> n >> k;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
    }
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(w+1, vector<int>(k+1, 0)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            for (int l = 1; l <= k; l++) {
                if (j-A[i-1] >= 0) {
                    dp[i][j][l] = max(dp[i-1][j-A[i-1]][l-1] + B[i-1], dp[i-1][j][l]);
                } else {
                    dp[i][j][l] = dp[i-1][j][l];
                }
            }
        }
    }
    cout << dp[n][w][k] << endl;
}