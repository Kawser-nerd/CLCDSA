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
    string s;
    cin >> s;

    int n = s.length();
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    rep(i, n / 2) {
        if (s[i] != s[n - 1 - i]) {
            cnt++;
        }
    }

    int m = 'Z' - 'A' + 1;
    if (cnt == 0) {
        cout << (m - 1) * n - (n % 2 != 0 ? m - 1 : 0) << endl;
    } else if (cnt == 1) {
        cout << (m - 1) * n - 2 << endl;
    } else {
        cout << (m - 1) * n << endl;
    }

    return 0;
}