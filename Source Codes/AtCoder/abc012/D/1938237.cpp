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
using std::setfill;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        a--;
        b--;
        g[a][b] = g[b][a] = t;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        int worst = 0;
        for (int j = 0; j < n; j++) {
            worst = max(worst, g[i][j]);
        }
        ans = min(ans, worst);
    }

    cout << ans << endl;

    return 0;
}