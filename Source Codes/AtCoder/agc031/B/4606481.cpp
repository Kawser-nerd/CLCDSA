#include <iostream>

#define MOD 1000000007

using namespace std;

int C[200005];
int pre[200005];
long dp[200005];

int main() {
    int n, c;
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        cin >> c;
        if (pre[c] > 0 && pre[c] != i - 1) {
            dp[i] = dp[i - 1] + dp[pre[c]];
            dp[i] %= MOD;
        } else {
            dp[i] = dp[i - 1];
        }
        pre[c] = i;
    }
    cout << dp[n] << endl;
}