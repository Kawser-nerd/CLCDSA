#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
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

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long int ll;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;

class point {
   public:
    ll x;
    ll y;
    point() {}
    point(ll x, ll y) : x(x), y(y) {}

    bool operator==(const point& p) const { return x == p.x && y == p.y; }
};

int main() {
    ll n;
    cin >> n;

    vector<point> ps(n);
    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        ps[i] = point(x, y);
    }

    ll cnt_lt_90 = 0;
    ll cnt_eq_90 = 0;

    for (const point& p : ps) {
        vector<double> ths;
        for (const point& q : ps) {
            if (p == q) {
                continue;
            }
            ll dx = q.x - p.x;
            ll dy = q.y - p.y;
            double th = atan2(dy, dx);
            ths.push_back(th);
        }

        sort(ths.begin(), ths.end());
        for (ll i = 0; i < n - 1; i++) {
            ths.push_back(ths[i] + 2 * M_PI);
        }

        ll i = 0;
        ll j = 0;
        double angle = 0;
        while (i < n - 1) {
            while (angle < M_PI / 2 - EPS) {
                angle += ths[j + 1] - ths[j];
                j++;
            }

            if (M_PI / 2 - EPS <= angle && angle <= M_PI / 2 + EPS) {
                cnt_eq_90 += 1;
            }
            cnt_lt_90 += j - i - 1;

            angle -= ths[i + 1] - ths[i];
            i++;
        }
    }

    ll cnt_all = n * (n - 1) * (n - 2) / 2;
    ll cnt_gt_90 = cnt_all - cnt_lt_90 - cnt_eq_90;

    ll donkaku = cnt_gt_90;
    ll chokkaku = cnt_eq_90;
    ll eikaku = (cnt_lt_90 - (2 * donkaku + 2 * chokkaku)) / 3;

    cout << eikaku << " " << chokkaku << " " << donkaku << endl;

    return 0;
}