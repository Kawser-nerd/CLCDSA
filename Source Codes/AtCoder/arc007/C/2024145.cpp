#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
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

int rotate_shift(int v, int n, int i) {
    int ans = (v >> i) | (v << (n - i));
    return ans & ((1 << n) - 1);
}

void print(int v, int n) {
    for (int i = n - 1; i >= 0; i--) putchar((v & (1 << i)) ? '1' : '0');
    putchar('\n');
}

int popcnt(int v) { return __builtin_popcount(v); }

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int p = 0;
    rep(i, n) {
        if (s[i] == 'o') {
            p |= 1 << (n - 1 - i);
        }
    }

    int ans = n;
    for (int s = 0; s < (1 << n); s++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (s & (1 << i)) {
                sum |= rotate_shift(p, n, i);
            }
        }
        if (sum != (1 << n) - 1) {
            continue;
        }
        ans = min(ans, popcnt(s));
    }

    cout << ans << endl;

    return 0;
}