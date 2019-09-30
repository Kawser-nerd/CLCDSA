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

int area(int n, vector<vector<int>>& a, int x, int y, int w, int h) {
    int ans = a[y + h][x + w];
    ans -= a[y + h][x];
    ans -= a[y][x + w];
    ans += a[y][x];
    return ans;
}

int solve(int n, vector<vector<int>>& a, int p) {
    int ans = 0;
    for (int h = 1; h <= p; h++) {
        if (p % h != 0) {
            continue;
        }
        const int w = p / h;

        for (int sy = 0; sy + h <= n; sy++) {
            for (int sx = 0; sx + w <= n; sx++) {
                ans = max(ans, area(n, a, sx, sy, w, h));
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = d[i - 1][j - 1];
            a[i][j] += a[i - 1][j];
            a[i][j] += a[i][j - 1];
            a[i][j] -= a[i - 1][j - 1];
        }
    }

    vector<int> opt(n * n + 1);
    for (int i = 1; i <= n * n; i++) {
        opt[i] = max(opt[i - 1], solve(n, a, i));
    }


    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int p;
        cin >> p;
        cout << opt[p] << endl;
    }

    return 0;
}