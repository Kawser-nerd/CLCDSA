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
    int n, m;
    cin >> n >> m;

    for (int b = 0; b <= n; b++) {
        if ((m - 3 * b) % 2 != 0) {
            continue;
        }
        const int d = n - b;
        const int e = (m - 3 * b) / 2;
        const int c = e - d;
        const int a = n - b - c;
        if (a >= 0 && c >= 0) {
            cout << a << " " << b << " " << c << endl;
            return 0;
        }
    }

    cout << "-1 -1 -1" << endl;

    return 0;
}