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

using std::lower_bound;
using std::upper_bound;

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

class person {
   public:
    int i;
    int r;
    int h;
    person() : i(0), r(0), h(0) {}
    person(int i, int r, int h) : i(i), r(r), h(h) {}

    bool operator<(const person& p) const {
        if (r == p.r) {
            return h < p.h;
        }
        return r < p.r;
    }
};

bool lt_r(const person& p1, const person& p2) { return p1.r < p2.r; }
bool lt_h(const person& p1, const person& p2) { return p1.h < p2.h; }

int main() {
    int n;
    cin >> n;

    vector<person> ps(n);
    for (int i = 0; i < n; i++) {
        int r, h;
        cin >> r >> h;
        h--;
        ps[i] = person(i, r, h);
    }

    sort(ps.begin(), ps.end());

    vector<int> win(n);
    vector<int> lose(n);
    vector<int> draw(n);
    for (int i = 0; i < n; i++) {
        int w = 0;
        int l = 0;
        int d = 0;

        auto lb_r = lower_bound(ps.begin(), ps.end(), ps[i], lt_r);
        auto ub_r = upper_bound(ps.begin(), ps.end(), ps[i], lt_r);
        w += lb_r - ps.begin();
        l += ps.end() - ub_r;

        w += upper_bound(lb_r, ub_r, person(0, 0, (ps[i].h + 1) % 3), lt_h) -
             lower_bound(lb_r, ub_r, person(0, 0, (ps[i].h + 1) % 3), lt_h);
        l += upper_bound(lb_r, ub_r, person(0, 0, (ps[i].h + 2) % 3), lt_h) -
             lower_bound(lb_r, ub_r, person(0, 0, (ps[i].h + 2) % 3), lt_h);
        d += upper_bound(lb_r, ub_r, person(0, 0, ps[i].h), lt_h) -
             lower_bound(lb_r, ub_r, person(0, 0, ps[i].h), lt_h);

        win[ps[i].i] = w;
        lose[ps[i].i] = l;
        draw[ps[i].i] = d - 1;
    }

    for (int i = 0; i < n; i++) {
        cout << win[i] << " " << lose[i] << " " << draw[i] << endl;
    }

    return 0;
}