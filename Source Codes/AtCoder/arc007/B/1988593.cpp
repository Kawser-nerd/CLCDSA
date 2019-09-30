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

    vector<int> t(m);
    rep(i, m) { cin >> t[i]; }

    vector<int> a(n);
    rep(i, n) { a[i] = i + 1; }

    int hand = 0;
    rep(i, m) {
        if (hand == t[i]) {
            continue;
        }
        int p = -1;
        rep(j, n) {
            if (a[j] == t[i]) {
                p = j;
                break;
            }
        }
        swap(hand, a[p]);
    }

    rep(i, n) { cout << a[i] << endl; }

    return 0;
}