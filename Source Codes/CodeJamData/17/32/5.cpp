#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int INF = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    int k = 24 * 60;
    vector<int> mars1(k + 2, 0), mars2(k + 2, 0);
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        mars1[l]++;
        mars1[r]--;
    }
    for (int i = 1; i <= m; ++i) {
        int l, r;
        cin >> l >> r;
        mars2[l]++;
        mars2[r]--;
    }
    for (int i = 1; i <= k; ++i) {
        mars1[i] += mars1[i - 1];
        mars2[i] += mars2[i - 1];
    }
    int ans = INF;
    for (int start = 0; start < 2; ++start) {
        vector<int> dp[2];
        vector<int> ndp[2];
        for (int i = 0; i < 2; ++i) {
            dp[i] = vector<int>(k / 2 + 1, INF);
            ndp[i] = vector<int>(k / 2 + 1, INF);
        }
        const vector<int>& mstart = (start == 0 ? mars1: mars2);
        // const vector<int>& mother = (start == 0 ? mars2: mars1);
        if (mstart[0] == 0) {
            if (start == 0) {
                dp[start][1] = 0;
            } else {
                dp[start][0] = 0;
            }
            for (int i = 1; i < k; ++i) {
                for (int u = 0; u < 2; ++u) {
                    fill(ndp[u].begin(), ndp[u].end(), INF);
                }
                if (mars2[i] == 0 && i + 1 <= k / 2) {
                    ndp[1][0] = min(dp[1][0], dp[0][0] + 1);
                }
                if (mars1[i] == 0 && i + 1 <= k / 2) {
                    ndp[0][i + 1] = min(dp[0][i], dp[1][i] + 1);
                }
                for (int j = 1; j <= i && j <= k / 2; ++j) {
                    int o = i + 1 - j;
                    if (o > k / 2) {
                        continue;
                    }
                    if (mars2[i] == 0) {
                        ndp[1][j] = min(dp[1][j], dp[0][j] + 1);
                    }
                    if (mars1[i] == 0) {
                        ndp[0][j] = min(dp[0][j - 1], dp[1][j - 1] + 1);
                    }
                }
                dp[0].swap(ndp[0]);
                dp[1].swap(ndp[1]);
            }
            ans = min(ans, dp[start][k / 2]);
            ans = min(ans, dp[start ^ 1][k / 2] + 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
