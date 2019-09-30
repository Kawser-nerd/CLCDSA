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
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> even(10);
    vector<int> odd(10);
    rep(i, n) {
        if (i % 2 == 0) {
            even[a[i]]++;
        } else {
            odd[a[i]]++;
        }
    }

    int ans = INF;
    rep(i, 10) {
        rep(j, 10) {
            if (i == j) {
                continue;
            }
            int even_cost = (n / 2 + n % 2) - even[i];
            int odd_cost = (n / 2) - odd[j];
            ans = min(ans, c * (even_cost + odd_cost));
        }
    }
    cout << ans << endl;

    return 0;
}