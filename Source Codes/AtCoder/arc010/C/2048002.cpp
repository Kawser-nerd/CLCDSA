#include <algorithm>
#include <cmath>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
#define int ll

const int MOD = 1e9 + 7;
const int INF = 1e15 + 373;

#define rep(i, n) for (int i = 0; i < (n); ++i)

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> init_vector2(size_t n0, size_t n1, T e = T()) {
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> init_vector3(size_t n0, size_t n1, size_t n2, T e = T()) {
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

// int solve(int n, int m, const vector<int>& a, const vector<int>& x, int y,
//           int z) {
//     const int all = (1 << m) - 1;
//
//     vector2<int> dp = init_vector2<int>(1 << m, m, -INF);
//
//     for (int i = 0; i < n; i++) {
//         vector2<int> dp2(dp);
//         for (int s = 0; s < (1 << m); s++) {
//             if (~s & (1 << a[i])) {
//                 continue;
//             }
//
//             const int z_point = s == all ? z : 0;
//
//             int ans = -INF;
//             if (dp[s][a[i]] != -INF) {
//                 ans = max(ans, dp[s][a[i]] + x[a[i]] + y);
//             }
//             for (int c = 0; c < m; c++) {
//                 if (~s & (1 << c) || a[i] == c) {
//                     continue;
//                 }
//                 if (dp[s][c] != -INF) {
//                     ans = max(ans, dp[s][c] + x[a[i]]);
//                 }
//                 if (dp[s & ~(1 << a[i])][c] != -INF) {
//                     ans = max(ans, dp[s & ~(1 << a[i])][c] + x[a[i]] +
//                     z_point);
//                 }
//             }
//             if(s == 1 << a[i]){
//                 ans = max(ans, x[a[i]]);
//             }
//             dp2[s][a[i]] = ans;
//         }
//         dp = dp2;
//     }
//
//     int ans = -INF;
//     rep(s, 1 << m) {
//         rep(c, m) { ans = max(ans, dp[s][c]); }
//     }
//
//     return ans;
// }
int solve(int n, int m, const vector<int>& a, const vector<int>& x, int y,
          int z) {
    const int all = (1 << m) - 1;

    vector2<int> dp = init_vector2<int>(1 << m, m + 1, -INF);
    dp[0][m] = 0;

    for (int i = 0; i < n; i++) {
        vector2<int> dp2(dp);
        for (int s = 0; s < (1 << m); s++) {
            for (int c = 0; c <= m; c++) {
                if (dp[s][c] == -INF) {
                    continue;
                }
                // throw it
                dp2[s][c] = max(dp2[s][c], dp[s][c]);
                // choose it
                int v = dp[s][c] + x[a[i]];
                if (a[i] == c) {
                    v += y;
                }
                if (s == (all & ~(1 << a[i]))) {
                    v += z;
                }
                dp2[s | (1 << a[i])][a[i]] = max(dp2[s | (1 << a[i])][a[i]], v);
            }
        }
        dp = dp2;
    }

    int ans = -INF;
    rep(s, 1 << m) {
        rep(c, m + 1) { ans = max(ans, dp[s][c]); }
    }

    return ans;
}

signed main() {
    int n, m, y, z;
    cin >> n >> m >> y >> z;

    vector<char> cs(m);
    vector<int> ps(m);
    rep(i, m) { cin >> cs[i] >> ps[i]; }

    string b;
    cin >> b;

    vector<int> a(n);
    rep(i, n) { a[i] = find(cs.begin(), cs.end(), b[i]) - cs.begin(); }

    cout << solve(n, m, a, ps, y, z) << endl;

    return 0;
}