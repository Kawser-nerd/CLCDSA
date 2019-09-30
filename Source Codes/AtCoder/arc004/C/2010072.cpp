#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 373;

#define rep(i, n) for (int i = 0; i < (n); ++i)

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> init_vector2(size_t n0, size_t n1, T e = T()) {
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> init_vector3(size_t n0, size_t n1, size_t n2, T e = T()) {
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll w = a % b;
        a = b;
        b = w;
    }
    return a;
}

ll lcd(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    ll x, y;
    scanf("%lld/%lld", &x, &y);

    ll xy_gcd = gcd(x, y);
    x /= xy_gcd;
    y /= xy_gcd;

    ll a = (2 * x - y) / y;
    ll b = (2 * x + y) / y;

    bool found = false;
    for (ll n = a; n <= b; n++) {
        if (!(1 <= n)) {
            continue;
        }

        ll m = n * (n + 1) / 2 - n / y * x;

        if (!(1 <= m && m <= n)) {
            continue;
        }

        ll s = (n * (n + 1) / 2 - m);
        ll t = n;
        ll st_gcd = gcd(s, t);
        s /= st_gcd;
        t /= st_gcd;

        if (s == x && t == y) {
            found = true;
            printf("%lld %lld\n", n, m);
        }
    }

    if (!found) {
        cout << "Impossible" << endl;
    }

    return 0;
}