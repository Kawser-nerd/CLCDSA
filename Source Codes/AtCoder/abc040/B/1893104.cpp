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
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    int ans = INF;
    for (int r = 1; r <= n; r++) {
        int c = n / r;
        ans = min(ans, n - r * c + abs(r - c));
    }

    cout << ans << endl;

    return 0;
}