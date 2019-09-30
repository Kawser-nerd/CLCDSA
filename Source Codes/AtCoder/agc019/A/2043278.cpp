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

ll subr(ll q, ll h, ll s, ll n) {
    ll ans = n * q;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                int v = i + 2 * j + 4 * k;
                if (v == n) {
                    ans = min(ans, i * q + j * h + k * s);
                }
            }
        }
    }
    return ans;
}

int main() {
    ll q, h, s, d;
    ll n;
    cin >> q >> h >> s >> d;
    cin >> n;

    n *= 4;

    ll ans = q * n;
    ans = min(ans, h * (n / 2) + subr(q, h, s, n % 2));
    ans = min(ans, s * (n / 4) + subr(q, h, s, n % 4));
    ans = min(ans, d * (n / 8) + subr(q, h, s, n % 8));
    cout << ans << endl;

    return 0;
}