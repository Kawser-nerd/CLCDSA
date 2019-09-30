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
    vector<bool> e(10);
    rep(i, 6) {
        int x;
        cin >> x;
        e[x] = true;
    }

    int b;
    cin >> b;

    vector<bool> l(10);
    rep(i, 6) {
        int x;
        cin >> x;
        l[x] = true;
    }

    int cnt1 = 0;
    rep(i, 10) {
        if (e[i] && l[i]) {
            cnt1++;
        }
    }

    e[b] = true;

    int cnt2 = 0;
    rep(i, 10) {
        if (e[i] && l[i]) {
            cnt2++;
        }
    }

    int ans = 0;
    if (cnt1 == 6) {
        ans = 1;
    } else if (cnt2 == 6) {
        ans = 2;
    } else if (cnt1 == 5) {
        ans = 3;
    } else if (cnt1 == 4) {
        ans = 4;
    } else if (cnt1 == 3) {
        ans = 5;
    } else {
        ans = 0;
    }

    cout << ans << endl;

    return 0;
}