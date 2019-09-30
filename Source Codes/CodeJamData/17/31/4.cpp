#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

constexpr double PI = acos(-1);

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    const double DINF = 1e99;
    vector<double> dp(k + 1, -DINF);
    vector<double> ndp(k + 1, -DINF);
    dp[0] = 0;
    for (const pair<int, int>& p: A) {
        int r = p.first, h = p.second;
        double topArea = PI * r * r;
        double sideArea = 2.0 * PI * r * h;
        fill(ndp.begin(), ndp.end(), -DINF);
        ndp[0] = 0;
        ndp[1] = topArea + sideArea;
        for (int j = 1; j <= k; ++j) {
            ndp[j] = max(ndp[j], dp[j]);
            ndp[j] = max(ndp[j], dp[j - 1] + sideArea);
        }
        dp.swap(ndp);
    }
    cout << dp[k] << '\n';
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
    cout << setprecision(9) << fixed;

    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
