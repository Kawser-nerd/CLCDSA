#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    using ll = long long;

    ll a, n, m;
    cin >> a >> n >> m;

    vector<ll> l(n);

    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    vector<int> d(n - 1);

    for (int i = 0; i < n - 1; i++) {
        d[i] = l[i + 1] - l[i] - 1;
    }

    sort(d.begin(), d.end());

    vector<int> csum(n);

    for (int i = 0; i < n - 1; i++) {
        csum[i + 1] = csum[i] + d[i];
    }

    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;

        ll ans = 0;

        int k = upper_bound(d.begin(), d.end(), x + y) - d.begin();
    
        ans += n;

        ans += csum[k];
        ans += (n - 1 - k) * (x + y);
        
        ans += min(x, l[0] - 1);
        ans += min(y, a - l[n - 1]);

        cout << ans << endl;
    }
}