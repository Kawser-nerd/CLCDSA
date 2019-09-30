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
    point() {}
    point(double x, double y) : x(x), y(y) {}
};

point center(const vector<point>& ps) {
    point ans(0, 0);
    for (const point& p : ps) {
        ans.x += p.x;
        ans.y += p.y;
    }
    ans.x /= ps.size();
    ans.y /= ps.size();
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

    double la = 0;
    for (int i = 0; i < n; i++) {
        la = max(la, a[i].x * a[i].x + a[i].y * a[i].y);
    }
    la = sqrt(la);

    const point center_b = center(b);
    for (int i = 0; i < n; i++) {
        b[i].x -= center_b.x;
        b[i].y -= center_b.y;
    }

    double lb = 0;
    for (int i = 0; i < n; i++) {
        lb = max(lb, b[i].x * b[i].x + b[i].y * b[i].y);
    }
    lb = sqrt(lb);

    cout << fixed << setprecision(16) << lb / la << endl;

    return 0;
}