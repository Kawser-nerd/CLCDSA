#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>

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
const int MOD = 1e9 + 7;

class cup {
   public:
    ll w;
    ll p;
    cup() {}
    cup(ll w, ll p) : w(w), p(p) {}
};

bool eval(ll n, ll k, const vector<cup> &cs, double r) {
    vector<double> a(n);
    for (ll i = 0; i < n; i++) {
        a[i] = 1.0 * cs[i].w * (cs[i].p - r);
    }

    sort(a.begin(), a.end(), std::greater<double>());

    double sum = 0;
    for(ll i = 0; i < k; i++){
        sum += a[i];
    }

    return sum >= 0;
}

int main() {
    ll n, k;
    cin >> n >> k;

    vector<cup> cs(n);
    for (ll i = 0; i < n; i++) {
        ll w, p;
        cin >> w >> p;
        cs[i] = cup(w, p);
    }

    ll max_p = 0;
    for (int i = 0; i < n; i++) {
        max_p = max(max_p, cs[i].p);
    }

    // [lb, ub)
    double ub = max_p + 1;
    double lb = 0;
    for (int i = 0; i < 256; i++) {
        double mid = (ub + lb) / 2;
        if (eval(n, k, cs, mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }

    cout << std::fixed << std::setprecision(10) << lb << endl;

    return 0;
}