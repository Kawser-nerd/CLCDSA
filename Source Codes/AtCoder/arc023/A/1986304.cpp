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

int f(int y, int m, int d) {
    if (m == 1 || m == 2) {
        y--;
        m += 12;
    }
    return 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 129;
}

int main() {
    int y, m, d;
    cin >> y >> m >> d;
    cout << f(2014, 5, 17) - f(y, m, d) << endl;
    return 0;
}