#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ll n, t, a, vt = 1, va = 1;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> t >> a;

        ll r = max( (vt - 1) / t + 1, (va - 1) / a + 1 );
        vt = t * r;
        va = a * r;
    }

    cout << vt + va << endl;

    return 0;
}