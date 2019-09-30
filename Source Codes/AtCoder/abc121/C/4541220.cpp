#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    using ll = long long;

    int n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (m > a[i].second) {
            ans += a[i].first * a[i].second;
            m -= a[i].second;
        } else {
            ans += a[i].first * m;
            break;
        }
    }

    cout << ans << endl;
}