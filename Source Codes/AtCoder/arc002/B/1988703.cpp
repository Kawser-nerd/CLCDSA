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

bool uruu(int n) {
    if (n % 400 == 0) {
        return true;
    }
    if (n % 100 == 0) {
        return false;
    }
    if (n % 4 == 0) {
        return true;
    }
    return false;
}

int main() {
    //                              1   2   3   4   5   6   7   8   9  10  11 12
    static vector<int> days = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static vector<int> udays = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);

    while (1) {
        if (y % m != 0) {
            d = 1;
            m++;

            if (m > 12) {
                m = 1;
                y++;
            }
            continue;
        }

        if ((y / m) % d != 0) {
            d++;
            if (uruu(y)) {
                if (d > udays[m]) {
                    d = 1;
                    m++;
                }
            } else {
                if (d > days[m]) {
                    d = 1;
                    m++;
                }
            }
            if (m > 12) {
                m = 1;
                y++;
            }
            continue;
        }
        break;
    }

out:
    printf("%d/%02d/%02d\n", y, m, d);

    return 0;
}