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
    int a, b;
    cin >> a >> b;

    int aa = a;
    if (a / 100 != 9) {
        aa = 900 + a % 100;
    } else if ((a / 10) % 10 != 9) {
        aa = 990 + a % 10;
    } else {
        aa = 999;
    }
    int pat_a = aa - b;

    int bb = b;
    if (b / 100 != 1) {
        bb = 100 + b % 100;
    } else if ((b / 10) % 10 != 0) {
        bb = 100 + b % 10;
    } else {
        bb = 100;
    }
    int pat_b = a - bb;

    cout << max(pat_a, pat_b) << endl;

    return 0;
}