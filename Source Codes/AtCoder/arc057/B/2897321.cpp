#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using ll = long long;

int N;
ll K;
int a[2000];
ll csum[2000];
ll dp[2000][2001];

int main(){
    cin >> N >> K;

    csum[0] = 0LL;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        csum[i] = a[i];
        if (i != 0) csum[i] += csum[i - 1];
    }
    ll all = csum[N - 1];
    ll inf = all + 10;

    if (all == K) {
        cout << 1 << endl;
        return 0;
    }
    if (0 == K) {
        cout << 0 << endl;
        return 0;
    }
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        dp[0][i] = inf;
        dp[i][0] = 0;
    }
    dp[0][N] = inf;
    dp[0][1] = 1;

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= N; ++j) {
            ll pretotal = csum[i - 1];
            ll prewins = dp[i - 1][j - 1];
            ll total = csum[i];
            ll towin = total * prewins / pretotal + 1;
            if (towin - prewins > a[i]) {
                towin = inf;
            }
            dp[i][j] = min(towin, dp[i - 1][j]);
        }
    }

    // cout << "  i(a[]): ";
    // for (int j = 0; j <= N; ++j) {
    //     cout << setw(4) << j;
    // }
    // cout << endl;
    // for (int i = 0; i < N; ++i) {
    //     cout << setw(3) <<i << "(" << setw(3) <<  a[i] << ")" <<": ";
    //     for (int j = 0; j <= N; ++j) {
    //         if (dp[i][j] == inf) cout << "   *";
    //         else cout << setw(4) << dp[i][j];
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    for (int j = 0; j <= N; ++j) {
        if (dp[N - 1][j] <= K) ans = j;
    }

    cout << ans << endl;
}