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
    int n, m;
    cin >> n >> m;

    vector2<int> b = init_vector2<int>(n, m);
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, m) { b[i][j] = s[j] - '0'; }
    }

    vector2<int> a = init_vector2<int>(n, m);
    for (int i = 0; i < n - 2; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (b[i][j] == 0) {
                continue;
            }
            int k = b[i][j];
            b[i][j] -= k;
            b[i + 1][j + 1] -= k;
            b[i + 1][j - 1] -= k;
            b[i + 2][j] -= k;
            a[i + 1][j] += k;
        }
    }

    rep(i, n) {
        rep(j, m) { cout << a[i][j]; }
        cout << endl;
    }

    return 0;
}