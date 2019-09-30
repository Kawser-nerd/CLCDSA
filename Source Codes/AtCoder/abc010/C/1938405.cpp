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
    double x, y;
    point() : x(0), y(0) {}
    point(double x, double y) : x(x), y(y) {}

    double distance(const point& p) {
        double dx = x - p.x;
        double dy = y - p.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main() {
    point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;

    double t, v;
    cin >> t >> v;

    int n;
    cin >> n;

    vector<point> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i].x >> ps[i].y;
    }

    double d = t * v;
    bool ans = false;
    for (int i = 0; i < n; i++) {
        if (a.distance(ps[i]) + b.distance(ps[i]) <= d) {
            ans = true;
            break;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}