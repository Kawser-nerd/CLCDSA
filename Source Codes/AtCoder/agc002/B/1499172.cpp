#include <iostream>
#include <vector>
#include <algorithm>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) y) { return (f)(begin(y), end(y), ## __VA_ARGS__); })(x)
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<bool> dp(n); dp[0] = true;
    vector<int> cnt(n, 1);
    repeat (i,m) {
        int x, y; cin >> x >> y;
        -- x; -- y;
        -- cnt[x]; ++ cnt[y];
        if (dp[x]) dp[y] = true;
        if (cnt[x] == 0) dp[x] = false;
    }
    cout << whole(count, dp, true) << endl;
    return 0;
}