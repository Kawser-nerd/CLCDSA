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
    vector2<int> a = init_vector2(4, 4, 0);
    rep(i, 4) {
        rep(j, 4) { cin >> a[i][j]; }
    }

    bool end = true;
    rep(i, 4) {
        rep(j, 4) {
            if (i + 1 < 4 && a[i][j] == a[i + 1][j]) {
                end = false;
                goto out;
            }
            if (j + 1 < 4 && a[i][j] == a[i][j + 1]) {
                end = false;
                goto out;
            }
        }
    }
out:
    cout << (end ? "GAMEOVER" : "CONTINUE") << endl;

    return 0;
}