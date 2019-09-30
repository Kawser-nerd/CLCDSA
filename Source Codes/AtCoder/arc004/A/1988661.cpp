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

class pos {
   public:
    double x;
    double y;

    pos() : x(0), y(0) {}
    pos(double x, double y) : x(x), y(y) {}

    pos operator+(const pos& p) const { return pos(x + p.x, y + p.y); }
    pos operator-(const pos& p) const { return pos(x - p.x, y - p.y); }

    pos rotate(double th) const {
        double cs = cos(th);
        double sn = sin(th);
        return pos(x * cs - y * sn, x * sn + y * cs);
    }

    double distance(const pos& p) const {
        double dx = x - p.x;
        double dy = y - p.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main() {
    double n;
    cin >> n;

    vector<pos> ps(n);
    rep(i, n) { cin >> ps[i].x >> ps[i].y; }

    double ans = 0;
    rep(i, n) {
        rep(j, n) { ans = max(ans, ps[i].distance(ps[j])); }
    }
    cout << fixed << setprecision(16) << ans << endl;
    return 0;
}