#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <functional>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
#define LOG(x) cout << #x << " := " << (x) << endl
#define _LOG(x) cout << "Momentai " << x << endl
typedef long long ll;
typedef long double Lf;

ll n, s;

ll f(ll b, ll n) {
    if (n < b) return n;
    else return f(b, n/b) + n%b;
}

ll bns(ll lhs, ll rhs) {
    if (lhs == rhs) return lhs;
    ll mid = (lhs+rhs+1) / 2;
    if (f(mid, n) < s) return bns(lhs, mid-1);
    else return bns(mid, rhs);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s;
    if (s == n) {cout << n+1 << endl; return 0; }
    ll ans = -1;

    int i;
    for (i = 2; n/i > 1e6; ++i) {
        ll lhs = n/i + 1, rhs = n/(i-1);
        if (f(rhs, n) % (i-1) == s % (i-1)) {
            ll x = bns(lhs, rhs);
            if (f(x, n) == s) ans = x;
        }
    }

    for (ll j = 1e6; j >= 2; --j) if (f(j, n) == s) ans = j;
    cout << ans << endl;

    return 0;
}