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

    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a][b] = g[b][a] = true;
    }

    for (int i = 0; i < n; i++) {
        vector<bool> f(n);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i != j && j != k && k != i && !g[i][k] && g[i][j] &&
                    g[j][k]) {
                    f[k] = true;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (f[i]) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}