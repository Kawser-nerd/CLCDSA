#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    using ll = long long;

    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> s(n + 1);

    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }

    map<ll, ll> m;

    m[0]++;
    
    ll ans = 0;
    
    for (int i = 1; i <= n; i++) {
        ans += m[s[i]];

        m[s[i]]++;
    }

    cout << ans << endl;
}