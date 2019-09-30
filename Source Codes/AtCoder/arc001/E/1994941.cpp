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

    double dot(const pos& p) const { return x * p.x + y * p.y; }
    double det(const pos& p) const { return x * p.y - y * p.x; }
};

double solve(int n, const vector<int>& l, const vector<int>& r) {
    double ans = 0;

    int sx = l[0];
    int sy = 0;

    while (sy < n) {
        double l_ang = -INF;
        double r_ang = +INF;
        int ly = sy;
        int ry = sy;

        for (int y = sy + 1; y <= n; y++) {
            if (1.0 * (l[y] - sx) / (y - sy) > l_ang) {
                l_ang = 1.0 * (l[y] - sx) / (y - sy);
                ly = y;
            }

            if (1.0 * (r[y] - sx) / (y - sy) < r_ang) {
                r_ang = 1.0 * (r[y] - sx) / (y - sy);
                ry = y;
            }

            if (l_ang >= r_ang) {
                break;
            }
        }

        if (ly < ry) {
            ans += pos(sx, sy).distance(pos(l[ly], ly));
            sx = l[ly];
            sy = ly;
        } else {
            ans += pos(sx, sy).distance(pos(r[ry], ry));
            sx = r[ry];
            sy = ry;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    int s, g;
    cin >> s >> g;

    vector<int> l(n);
    vector<int> r(n);
    rep(i, n + 1) { cin >> l[i] >> r[i]; }

    l[0] = s;
    r[0] = s;
    l[n] = g;
    r[n] = g;

    cout << fixed << setprecision(16) << solve(n, l, r) << endl;

    return 0;
}