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

int popcnt(int n) { return __builtin_popcount(n); }

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x][y] = g[y][x] = true;
    }

    int ans = 0;
    for (int s = 0; s < (1 << n); s++) {
        bool creek = true;
        for (int i = 0; i < n; i++) {
            if (!(s & (1 << i))) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (!(s & (1 << j))) {
                    continue;
                }
                if (!g[i][j]) {
                    creek = false;
                    goto outer;
                }
            }
        }
    outer:
        if (creek) {
            ans = max(ans, popcnt(s));
        }
    }

    cout << ans << endl;

    return 0;
}