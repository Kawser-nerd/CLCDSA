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

int main() {
    ll n;
    cin >> n;

    vector<ll> x(n);
    vector<ll> y(n);
    rep(i, n) { cin >> x[i] >> y[i]; }

    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            for (ll k = j + 1; k < n; k++) {
                ll vx = x[j] - x[i];
                ll vy = y[j] - y[i];
                ll ux = x[k] - x[i];
                ll uy = y[k] - y[i];
                ll area2 = abs(vx * uy - vy * ux);
                if (area2 > 0 && area2 % 2 == 0) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;

    return 0;
}