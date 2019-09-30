#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;

using std::fixed;
using std::setprecision;
using std::setw;

typedef long long int ll;
const int MOD = 1e9 + 7;
const ll INF = 1e15 + 314;

int main() {
    ll n, k;
    cin >> n >> k;

    ll sum = 0;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if(k == sum){
        cout << 1 << endl;
        return 0;
    }

    vector<vector<ll>> dp(n, vector<ll>(n + 1, 0));
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (ll j = 2; j <= n; j++) {
        dp[0][j] = INF;
    }

    sum = a[0];
    for (ll i = 1; i < n; i++) {
        // sum = a[0] ... a[i - 1]
        for (ll j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][j - 1] == INF) {
                continue;
            }
            ll x = 1 + a[i] * dp[i - 1][j - 1] / sum;
            if(x > a[i]){
                continue;
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + x);
        }
        sum += a[i];
    }

    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){
            cout << setw(10) << dp[i][j] << " ";
        }
        cout << endl;
    }
    */


    ll ans = -1;
    for (ll j = n; j >= 0; j--) {
        if (dp[n - 1][j] <= k) {
            ans = j;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}