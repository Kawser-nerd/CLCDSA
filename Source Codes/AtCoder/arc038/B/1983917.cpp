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

vector2<int> memo = init_vector2(100, 100, -1);
int solve(const vector<string>& s, int h, int w, int i, int j) {
    static vector<int> dy = {1, 0, 1};
    static vector<int> dx = {0, 1, 1};

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (i == h - 1 && j == w - 1) {
        return memo[i][j] = 0;
    }

    rep(k, 3) {
        int y = i + dy[k];
        int x = j + dx[k];
        if (y < h && x < w && s[y][x] == '.' && solve(s, h, w, y, x) == 0) {
            return memo[i][j] = 1;
        }
    }

    return memo[i][j] = 0;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) { cin >> s[i]; }

    cout << (solve(s, h, w, 0, 0) == 1 ? "First" : "Second") << endl;

    return 0;
}