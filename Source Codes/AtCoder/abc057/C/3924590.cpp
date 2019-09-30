#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
typedef long long ll;
using namespace std;

int main() {
    ll n; cin >> n;
    ll s = ll(sqrt(n));
    if (s*s<n) {
        s++;
    }
    for (ll i = s; i>0; i--) {
        if (n%i==0) {
            ll q = n/i;
            ll ans = 0;
            while (q) {
                q/=10;
                ans++;
            }
            cout << ans << endl;
            break;
        }
    }
    return 0;
}