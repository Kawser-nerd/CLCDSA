#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

// dp??i?????????????????ver
const int match[10] = {0,2,5,5,4,5,6,3,7,6};
int n, m, a[10], dp[10010];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    sort(a, a+m, greater<int>());

    fill(dp, dp+10010, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int prev = i - match[a[j]];
            if (prev >= 0) {
                dp[i] = max(dp[i], dp[prev] + 1);
            }
        }
    }

    string ans = "";
    int cur = n;
    while (cur > 0) {
        for (int i = 0; i < m; i++) {
            if  (cur - match[a[i]] >= 0 && dp[cur] == dp[cur - match[a[i]]] + 1) {
                ans += to_string(a[i]);
                cur -= match[a[i]];
                break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}