#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <set>
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
    int n;
    cin >> n;

    vector<string> w(n);
    rep(i, n) { cin >> w[i]; }

    set<string> s;
    s.insert(w[0]);

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s.count(w[i]) > 0 || w[i - 1].back() != w[i].front()) {
            ans = i % 2 == 0 ? -1 : 1;
            break;
        }
        s.insert(w[i]);
    }

    if (ans == 1) {
        cout << "WIN" << endl;
    }
    if (ans == -1) {
        cout << "LOSE" << endl;
    }
    if (ans == 0) {
        cout << "DRAW" << endl;
    }
    return 0;
}