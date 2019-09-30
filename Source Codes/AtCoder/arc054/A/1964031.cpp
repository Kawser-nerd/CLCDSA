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
    int l, x, y, s, d;
    cin >> l >> x >> y >> s >> d;

    int clkwiz_d = (d - s + l) % l;
    int cclkwiz_d = (s + l - d) % l;

    double ans = 1.0 * clkwiz_d / (x + y);
    if (y - x > 0) {
        ans = min(ans, 1.0 * cclkwiz_d / (y - x));
    }

    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}