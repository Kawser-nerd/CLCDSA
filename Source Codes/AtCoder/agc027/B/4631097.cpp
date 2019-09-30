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
const ll INF = 1LL << 60;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;

    ll sm[n+1];
    sm[0] = 0;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        sm[i] = sm[i-1] + a;
    }

    ll ans = INF;
    for (ll i = 1; i <= n; i++) {
        // i?????
        ll cost = (n + i) * x;
        ll pos = n;
        cost += sm[pos] * 5;
        pos -= i * 2;
        while (pos > 0) {
            cost += sm[pos] * 2;
            pos -= i;
            if (cost < 0) {
                cost = INF;
                break;
            }
        }
        ans = min(ans, cost);
    }

    cout << ans << "\n";
    return 0;
}