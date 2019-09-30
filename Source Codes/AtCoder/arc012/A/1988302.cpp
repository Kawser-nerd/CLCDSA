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
    string d;
    cin >> d;

    int ans = -1;
    if (d == "Sunday") {
        ans = 0;
    } else if (d == "Monday") {
        ans = 5;
    } else if (d == "Tuesday") {
        ans = 4;
    } else if (d == "Wednesday") {
        ans = 3;
    } else if (d == "Thursday") {
        ans = 2;
    } else if (d == "Friday") {
        ans = 1;
    } else if (d == "Saturday") {
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}