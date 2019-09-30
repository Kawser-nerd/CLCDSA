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

    point operator-(const point& p) const { return point(x - p.x, y - p.y); }
};

double area(const point& p, const point& q) { return p.x * q.y - p.y * q.x; }

bool intersect(const point& p1, const point& p2, const point& q1,
               const point& q2) {
    return area(p2 - p1, q1 - p1) * area(p2 - p1, q2 - p1) < 0 &&
           area(q2 - q1, p1 - q1) * area(q2 - q1, p2 - q1) < 0;
}

int main() {
    point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;

    int n;
    cin >> n;

    vector<point> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i].x >> ps[i].y;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (intersect(a, b, ps[i], ps[j])) {
            cnt++;
        }
    }
    cout << 1 + cnt / 2 << endl;

    return 0;
}