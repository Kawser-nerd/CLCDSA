#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

ll dp[5005][5005];
// ??i????????i?????j????????????

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n, a, b;
    cin >> n >> a >> b;

    ll p[n];
    map <ll, int> pos;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = dp[i-1][j];
            if (j < pos[i]) dp[i][j] += b;
            if (j > pos[i]) dp[i][j] += a;
            if (j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }

    cout << dp[n][n-1] << "\n";
    return 0;
}