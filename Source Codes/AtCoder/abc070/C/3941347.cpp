#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
typedef long long ll;
using namespace std;

ll gcm(ll a, ll b) {
    if (a < b) return gcm(b, a);
    if (b==0) return a;
    return gcm(b, a%b);
}

int main() {
    
    ll n; cin >> n;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        ans = ans/gcm(ans, t)*t;
    }
    cout << ans << endl;
    return 0;
}