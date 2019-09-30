#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
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
const int MOD = 1e9 + 7;

double f(int r) { return 1.0 * r * r * M_PI; }

int main() {
    int n;
    cin >> n;

    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    sort(r.begin(), r.end(), std::greater<int>());

    bool color = true;
    double ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (color) {
            ans += f(r[i]) - f(r[i + 1]);
        }
        color = !color;
    }

    if (color) {
        ans += f(r[n - 1]);
    }

    cout << std::fixed << std::setprecision(15) << ans << endl;

    return 0;
}