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
    int n;
    cin >> n;

    string s1;
    cin >> s1;
    string s2;
    cin >> s2;

    bool update = true;
    while (update) {
        update = false;
        rep(i, n) {
            if (s1[i] == s2[i]) {
                continue;
            }
            update = true;
            int a = min(s1[i], s2[i]);
            int b = max(s1[i], s2[i]);
            rep(j, n) {
                if (s1[j] == b) {
                    s1[j] = a;
                }
                if (s2[j] == b) {
                    s2[j] = a;
                }
            }
        }
    }

    vector<bool> used(128);
    rep(i, n) { used[s1[i]] = true; }

    int cnt = 0;
    for (int i = 'A'; i <= 'Z'; i++) {
        if (used[i]) {
            cnt++;
        }
    }

    ll ans = 1;
    if ('A' <= s1[0] && s1[0] <= 'Z') {
        ans *= 9;
        cnt--;
    }

    rep(i, cnt) { ans *= 10; }

    cout << ans << endl;

    return 0;
}