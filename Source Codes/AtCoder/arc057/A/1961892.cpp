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

int main() {
    const ll TARGET = (ll)2e12;
    ll a, k;
    cin >> a;
    cin >> k;

    if (a >= TARGET) {
        cout << 0 << endl;
        return 0;
    }

    if (k == 0) {
        cout << TARGET - a << endl;
        return 0;
    }

    ll t = 0;
    while (a < TARGET) {
        a += 1 + k * a;
        t++;
    }

    cout << t << endl;

    return 0;
}