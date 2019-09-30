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

int cap(int na, int nb, const vector<int>& a, const vector<int>& b) {
    int ans = 0;
    int j = 0;
    rep(i, na) {
        while (j < nb && b[j] < a[i]) {
            j++;
        }
        if (j == nb) {
            break;
        }
        if (a[i] == b[j]) {
            ans++;
        }
    }

    return ans;
}

int main() {
    int na, nb;
    cin >> na >> nb;

    vector<int> a(na);
    rep(i, na) { cin >> a[i]; }
    sort(a.begin(), a.end());

    vector<int> b(nb);
    rep(i, nb) { cin >> b[i]; }
    sort(b.begin(), b.end());

    int p = cap(na, nb, a, b);
    int q = na + nb - p;

    cout << fixed << setprecision(16) << 1.0 * p / q << endl;

    return 0;
}