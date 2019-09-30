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
    int n, l;
    cin >> n >> l;

    vector<string> a(l + 1);
    getline(cin, a[0]);
    rep(i, l + 1) { getline(cin, a[i]); }

    int p = -1;
    rep(i, a[l].size()) {
        if (a[l][i] == 'o') {
            p = i;
            break;
        }
    }

    for (int j = l - 1; j >= 0; j--) {
        if (p - 1 >= 0 && a[j][p - 1] == '-') {
            p -= 2;
        } else if (p + 1 < a[j].size() && a[j][p + 1] == '-') {
            p += 2;
        }
    }

    cout << 1 + p / 2 << endl;

    return 0;
}