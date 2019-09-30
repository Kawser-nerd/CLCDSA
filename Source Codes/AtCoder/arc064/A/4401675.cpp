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

int main() {
    int n;
    ll x;
    cin >> n >> x;

    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i-1] > x) {
            ans += a[i] + (a[i-1] - x);
            a[i] = 0;
        } else {
            ll d = x - a[i-1];
            ans += max(0LL, a[i] - d);
            a[i] = min(d, a[i]);
        }
    }

    cout << ans << "\n";
    return 0;
}