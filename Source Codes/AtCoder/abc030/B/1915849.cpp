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

int main() {
    int n, m;
    cin >> n >> m;
    n = (n % 12);

    double i = 5.0 * (n + m / 60.0);
    double j = m;

    double s = min(i, j);
    double t = max(i, j);

    double d = min(t - s, 60 - (t - s));
    cout << std::fixed << std::setprecision(10) << 360.0 * d / 60 << endl;

    return 0;
}