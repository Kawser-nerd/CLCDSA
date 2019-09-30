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

int f(int m, int d) {
    //                          1   2   3   4   5   6   7   8   9  10  11  12
    static vector<int> days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    m--;
    d--;

    int j = 0;
    for (int i = 0; i < m; i++) {
        j += days[i];
    }
    return j + d;
}

int main() {
    int n;
    cin >> n;

    vector<bool> a(366);
    rep(i, 366) {
        if (i % 7 == 0) {
            a[i] = true;
        }
        if (i % 7 == 6) {
            a[i] = true;
        }
    }

    rep(i, n) {
        int m, d;
        scanf("%d/%d", &m, &d);

        int j = f(m, d);
        while (j < 366 && a[j]) {
            j++;
        }
        if (j < 366) {
            a[j] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < 366; i++) {
        int cnt = 0;
        for (int j = i; j < 366 && a[j]; j++) {
            cnt++;
        }
        ans = max(ans, cnt);
    }

    printf("%d\n", ans);

    return 0;
}