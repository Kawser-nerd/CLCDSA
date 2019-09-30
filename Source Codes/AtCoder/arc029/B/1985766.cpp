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
};

class rect {
   public:
    pos s;
    pos t;

    rect() : s(pos()), t(pos()) {}
    rect(const pos& s, const pos& t) : s(s), t(t) {}

    bool contains(const pos& p) const {
        return s.x <= p.x && p.x <= t.x && s.y <= p.y && p.y <= t.y;
    }
};

bool solve(ll a, ll b, ll c, ll d) {
    if ((a <= c && b <= d) || (a <= d && b <= c)) {
        return true;
    }
    if (a * b > c * d) {
        return false;
    }

    pos p1(0, 0);
    pos p2(a, 0);
    pos p3(a, b);
    pos p4(0, b);

    double lb = 0;
    double ub = M_PI / 2;
    for (int i = 0; i < 2048; i++) {
        double mid = lb + (ub - lb) / 2;
        if (p3.rotate(mid).y <= d) {
            lb = mid;
        } else {
            ub = mid;
        }
    }

    p1 = p1.rotate(lb);
    p2 = p2.rotate(lb);
    p3 = p3.rotate(lb);
    p4 = p4.rotate(lb);

    p1.x -= p4.x;
    p2.x -= p4.x;
    p3.x -= p4.x;
    p4.x -= p4.x;

    rect r(pos(0, 0), pos(c, d));

    return r.contains(p1) && r.contains(p2) && r.contains(p3) && r.contains(p4);
}

int main() {
    int a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    rep(i, n) {
        int c, d;
        cin >> c >> d;
        if (a < b) {
            swap(a, b);
        }
        if (c < d) {
            swap(c, d);
        }
        cout << (solve(a, b, c, d) ? "YES" : "NO") << endl;
    }
    return 0;
}