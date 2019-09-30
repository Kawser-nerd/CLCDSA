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

int solve(int n, const string& c, const string& l, const string& r, int i,
          vector<int>& memo) {
    if (memo[i] != -1) {
        return memo[i];
    }

    for (int j = i; j < n - 1; j++) {
        if ((c[j] == l[0] && c[j + 1] == l[1]) ||
            (c[j] == r[0] && c[j + 1] == r[1])) {
            return memo[i] = (j - i) + min(solve(n, c, l, r, j + 1, memo) + 1,
                                           solve(n, c, l, r, j + 2, memo) + 1);
        }
    }

    return memo[i] = n - i;
}

int main() {
    int n;
    cin >> n;

    string c;
    cin >> c;

    int ans = n;
    vector<char> b = {'A', 'B', 'X', 'Y'};

    rep(l0, 4) {
        rep(l1, 4) {
            rep(r0, 4) {
                rep(r1, 4) {
                    string l = {b[l0], b[l1]};
                    string r = {b[r0], b[r1]};
                    if (l >= r) {
                        continue;
                    }
                    vector<int> memo(n + 1, -1);
                    ans = min(ans, solve(n, c, l, r, 0, memo));
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}