#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using ll = long long;
using namespace std;
bool solve(int n, vector<int> & a, vector<vector<int> > & g) {
    vector<int> dp(n);
    auto is_leaf = [&](int i) { return g[i].size() == 1; };
    function<bool (int, int)> go = [&](int i, int parent) {
        if (is_leaf(i)) {
            dp[i] = a[i];
        } else {
            ll sum_dp = 0;
            for (int j : g[i]) if (j != parent) {
                if (not go(j, i)) return false;
                sum_dp += dp[j];
            }
            if (sum_dp < a[i]) return false;
            ll b = sum_dp - a[i];
            ll c = a[i] - b;
            if (b < 0 or c < 0) return false;
            int argmax_dp = *whole(max_element, g[i], [&](int j, int k) { return make_pair(j != i, dp[j]) < make_pair(k != i, dp[k]); });
            ll max_dp = dp[argmax_dp];
            if (max_dp > sum_dp / 2) {
                if (sum_dp - max_dp < b) return false;
            } else {
                if (sum_dp / 2 < b) return false;
            }
            dp[i] = c;
        }
        return true;
    };
    assert (n >= 2);
    if (n == 2) {
        return a[0] == a[1];
    } else {
        int i = 0;
        while (is_leaf(i)) ++ i;
        if (not go(i, -1)) return false;
        return dp[i] == 0;
    }
}
int main() {
    int n; cin >> n;
    vector<int> a(n); repeat (i,n) cin >> a[i];
    vector<vector<int> > g(n);
    repeat (i,n-1) {
        int x, y; cin >> x >> y; -- x; -- y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << (solve(n, a, g) ? "YES" : "NO") << endl;
    return 0;
}