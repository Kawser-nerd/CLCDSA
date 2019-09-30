#include <algorithm>
#include <complex>
#include <iostream>
#include <numeric>
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

using std::accumulate;

typedef long long int ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 7;

class section {
   public:
    ll begin;
    ll end;
    ll velocity;

    section() {}
    section(ll begin, ll end) : begin(begin), end(end) {}
};

int main() {
    ll n;
    cin >> n;

    vector<section> ss(n);
    ll sum_t = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        x *= 2;

        ss[i].begin = sum_t;
        ss[i].end = sum_t + x;

        sum_t += x;
    }

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ss[i].velocity = 2 * x;
    }

    vector<ll> a(sum_t + 1, INF);
    a[0] = 0;
    a[sum_t] = 0;

    for (const section& s : ss) {
        for (ll i = s.begin; i <= s.end; i++) {
            a[i] = min(a[i], s.velocity);
        }
    }

    for (ll i = sum_t - 1; i >= 0; i--) {
        a[i] = min(a[i + 1] + 1, a[i]);
    }

    ll speed = 0;
    ll distance = 0;
    for (ll i = 0; i < sum_t; i++) {
        distance += speed;
        if (speed < a[i + 1]) {
            speed += 1;
            distance += 1;
        } else if (speed > a[i + 1]) {
            speed -= 1;
            distance -= 1;
        }
    }

    cout << std::fixed << std::setprecision(9) << (1.0 * distance / 4) << endl;

    return 0;
}