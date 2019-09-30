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

int solve(int n, vector<vector<bool>> g, int s, int t) {
    vector<bool> v(n);
    v[s] = true;

    vector<int> a(n);
    a[s] = 1;

    vector<bool> q(n);
    q[s] = true;

    while (!q[t]) {
        vector<bool> next_q(n);

        for (int i = 0; i < n; i++) {
            if (!q[i]) {
                continue;
            }
            v[i] = true;
        }

        for (int i = 0; i < n; i++) {
            if (!q[i]) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (g[i][j] && !v[j]) {
                    a[j] = (a[i] + a[j]) % MOD;
                    next_q[j] = true;
                }
            }
        }

        q = next_q;
    }

    return a[t];
}

int main() {
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;
    a--;
    b--;

    vector<vector<bool>> g(n, vector<bool>(n));

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x][y] = g[y][x] = true;
    }

    cout << solve(n, g, a, b) << endl;

    return 0;
}