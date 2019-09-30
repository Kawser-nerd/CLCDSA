#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const double EPS = 1e-9;

double getProb(const vector<double>& A, int k) {
    int n = SZ(A);
    vector<double> dp(k, 0);
    vector<double> ndp(k, 0);
    dp[0] = 1;
    for (double p: A) {
        fill(ndp.begin(), ndp.end(), 0);
        for (int i = 0; i + 1 < k; ++i) {
            ndp[i + 1] += dp[i] * p;
        }
        for (int i = 0; i < k; ++i) {
            ndp[i] += dp[i] * (1 - p);
        }
        dp.swap(ndp);
    }
    double ans = 1;
    for (int i = 0; i < k; ++i) {
        ans -= dp[i];
    }
    return ans;
}

vector<double> getBig(vector<double> A, int k, double U) {
    A.push_back(1);
    int n = SZ(A);
    while (U > EPS) {
        int pos = -1;
        for (int i = k + 1; i < n; ++i) {
            if (A[i] > A[k] + EPS) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            break;
        }
        double add = min(U / (pos - k), (A[pos] - A[k]) / pos);
        for (int i = k; i < pos; ++i) {
            A[i] += add;
        }
        U -= add * (pos - k);
    }
    int pos = n - 1;
    while (pos >= 0 && A[pos] + EPS > 1) {
        --pos;
    }
    while (pos >= 0) {
        double x = min(U, 1 - A[pos]);
        A[pos] += x;
        U -= x;
        pos--;
    }
    A.pop_back();
    return A;
}

void solve() {
    int n, k;
    double U;
    cin >> n >> k >> U;
    vector<double> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<double> B = getBig(A, i, U);
        double v = getProb(B, k);
        ans = max(ans, v);
        //cerr << i << ' ' << v << endl;
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
    cout << setprecision(13) << fixed;

    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
        //cerr << "Test " << t << "solved" << endl;
    }
}
