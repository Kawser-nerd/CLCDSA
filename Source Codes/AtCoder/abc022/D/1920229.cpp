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

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

class point {
   public:
    double x;
    double y;
    point() : x(0), y(0) {}
    point(double x, double y) : x(x), y(y) {}
};

point center(const vector<point>& ps) {
    point ans;
    for (const point& p : ps) {
        ans.x += p.x;
        ans.y += p.y;
    }
    ans.x /= ps.size();
    ans.y /= ps.size();
    return ans;
}

double variance(int n, const vector<point>& a, double p) {
    double ans = 0;
    for (int i = 0; i < n; i++) {
        double x = p * a[i].x;
        double y = p * a[i].y;
        ans += x * x + y * y;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<point> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }

    vector<point> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i].x >> b[i].y;
    }

    const point center_a = center(a);
    for (int i = 0; i < n; i++) {
        a[i].x -= center_a.x;
        a[i].y -= center_a.y;
    }

    const point center_b = center(b);
    for (int i = 0; i < n; i++) {
        b[i].x -= center_b.x;
        b[i].y -= center_b.y;
    }

    const double variance_b = variance(n, b, 1.0);

    // [lb, ub)
    double lb = 1;
    double ub = 1e10;
    for (int i = 0; i < 1e3; i++) {
        double mid = (ub + lb) / 2;
        if (variance(n, a, mid) <= variance_b) {
            lb = mid;
        } else {
            ub = mid;
        }
    }

    cout << fixed << setprecision(16);
    cout << lb << endl;

    return 0;
}