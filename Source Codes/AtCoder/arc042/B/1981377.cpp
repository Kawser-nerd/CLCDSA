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

    pos rotate(double th) const {
        double cs = cos(th);
        double sn = sin(th);
        return pos(x * cs - y * sn, x * sn + y * cs);
    }
};

double measure(const pos& p1, const pos& p2, const pos& q) {
    pos s = p2 - p1;
    pos t = q - p1;

    double th = atan2(s.y, s.x);
    pos tt = t.rotate(-th);
    return abs(tt.y);
}

int main() {
    pos q;
    cin >> q.x >> q.y;

    int n;
    cin >> n;

    vector<pos> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i].x >> ps[i].y;
    }

    double ans = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, measure(ps[i], ps[(i + 1) % n], q));
    }

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}