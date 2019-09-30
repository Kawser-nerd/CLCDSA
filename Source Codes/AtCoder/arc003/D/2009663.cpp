#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <queue>
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

bool trial(int n, int k, const vector2<bool>& g) {
    vector<int> a(n);
    rep(i, n) { a[i] = i; }

    rep(i, k) {
        int s = rand() % n;
        int t = (s + 1 + rand() % (n - 1)) % n;
        swap(a[s], a[t]);
    }

    rep(i, n) {
        int s = a[i];
        int t = a[(i + 1) % n];
        if (g[s][t]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    srand(time(NULL));

    vector2<bool> g = init_vector2(n, n, false);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }

    int t = 1000 * 1000;
    int c = 0;
    rep(i, t) {
        if (trial(n, k, g)) {
            c++;
        }
    }

    cout << fixed << setprecision(16) << (1.0 * c / t) << endl;

    return 0;
}