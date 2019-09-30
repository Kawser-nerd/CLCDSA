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
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    string w;
    cin >> w;

    vector<string> c(9);
    rep(i, 9) { cin >> c[i]; }

    int dx, dy;
    if (w == "R") {
        dx = 1;
        dy = 0;
    } else if (w == "L") {
        dx = -1;
        dy = 0;
    } else if (w == "U") {
        dx = 0;
        dy = -1;
    } else if (w == "D") {
        dx = 0;
        dy = 1;
    } else if (w == "RU") {
        dx = 1;
        dy = -1;
    } else if (w == "RD") {
        dx = 1;
        dy = 1;
    } else if (w == "LU") {
        dx = -1;
        dy = -1;
    } else if (w == "LD") {
        dx = -1;
        dy = 1;
    }

    rep(k, 4) {
        cout << c[y][x];

        y += dy;
        x += dx;

        if (y < 0) {
            y = 1;
            dy *= -1;
        }
        if (y >= 9) {
            y = 7;
            dy *= -1;
        }
        if (x < 0) {
            x = 1;
            dx *= -1;
        }
        if (x >= 9) {
            x = 7;
            dx *= -1;
        }
    }

    cout << endl;

    return 0;
}