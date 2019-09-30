#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
const int MOD = 1e9 + 7;
const double INF = 1e18;

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

vector<double> dijkstra(int n, const vector2<double>& g, int s) {
    vector<double> d(n, INF);
    d[s] = 0;

    typedef pair<double, int> P;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(make_pair(0, s));

    while (not q.empty()) {
        double c = q.top().first;
        int v = q.top().second;
        q.pop();

        if (c > d[v]) {
            continue;
        }

        rep(u, n) {
            double alt_c = c + g[v][u];
            if (alt_c < d[u]) {
                d[u] = alt_c;
                q.push(make_pair(alt_c, u));
            }
        }
    }

    return d;
}

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);
    vector<int> t(n);
    vector<int> r(n);
    rep(i, n) { cin >> x[i] >> y[i] >> t[i] >> r[i]; }

    vector2<double> g = init_vector2(n, n, INF);
    rep(i, n) {
        rep(j, n) {
            double d = hypot(x[i] - x[j], y[i] - y[j]);
            double s = min(t[i], r[j]);
            g[i][j] = d / s;
        }
    }

    vector<double> l = dijkstra(n, g, 0);
    sort(l.begin(), l.end(), greater<double>());

    rep(i, n) { l[i] += i; }
    l[n - 1] = 0;

    double ans = *max_element(l.begin(), l.end());
    cout << fixed << setprecision(16) << ans << endl;

    return 0;
}