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

bool valid(const vector<string>& c, int j, int i) {
    static const vector<int> dy = {0, 0, 1, -1, 1, 1, -1, -1};
    static const vector<int> dx = {1, -1, 0, 0, 1, -1, 1, -1};

    rep(k, 8) {
        for (int y = j + dy[k], x = i + dx[k];
             0 <= y && y < 8 && 0 <= x && x < 8;
             y += dy[k], x += dx[k]) {
            if (c[y][x] == 'Q') {
                return false;
            }
        }
    }

    return true;
}

bool search(vector<string>& c, int d) {
    if (d == 8) {
        return true;
    }

    rep(i, 8) {
        if (c[d][i] == 'Q') {
            return valid(c, d, i) && search(c, d + 1);
        }
    }

    rep(i, 8) {
        if (valid(c, d, i)) {
            c[d][i] = 'Q';
            if (search(c, d + 1)) {
                return true;
            }
            c[d][i] = '.';
        }
    }

    return false;
}

int main() {
    vector<string> c(8);
    rep(i, 8) { cin >> c[i]; }

    bool ans = search(c, 0);
    if (!ans) {
        cout << "No Answer" << endl;
    } else {
        rep(i, 8) { cout << c[i] << endl; }
    }

    return 0;
}