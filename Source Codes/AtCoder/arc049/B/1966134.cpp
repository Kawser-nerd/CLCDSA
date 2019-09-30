#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;

using std::fixed;
using std::setprecision;
using std::setw;

using ll = long long int;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 373;

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

bool intersect(const rect& r1, const rect& r2, rect* out = nullptr) {
    vector<double> xs = {r1.s.x, r1.t.x, r2.s.x, r2.t.x};
    vector<double> ys = {r1.s.y, r1.t.y, r2.s.y, r2.t.y};
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    rect ans(pos(xs[1], ys[1]), pos(xs[2], ys[2]));

    if (not(r1.contains(ans.s) && r2.contains(ans.s) && r1.contains(ans.t) &&
            r2.contains(ans.t))) {
        return false;
    }

    if (out != nullptr) {
        *out = ans;
    }

    return true;
}

bool eval(int n, const vector<pos>& ps, const vector<double>& cs, double t) {
    if (t < 0) {
        return false;
    }

    vector<rect> rs(n);
    for (int i = 0; i < n; i++) {
        double d = t / cs[i];
        rs[i].s = pos(ps[i].x - d, ps[i].y - d);
        rs[i].t = pos(ps[i].x + d, ps[i].y + d);
    }

    rect w = rs[0];
    for (int i = 1; i < n; i++) {
        if (!intersect(w, rs[i], &w)) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<pos> ps(n);
    vector<double> cs(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i].x >> ps[i].y >> cs[i];
    }

    // (lb, ub]
    double ub = 1e18;
    double lb = -1;
    for (int i = 0; i < 2048; i++) {
        double mid = lb + (ub - lb) / 2;
        if (eval(n, ps, cs, mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }

    cout << fixed << setprecision(9) << ub << endl;

    return 0;
}