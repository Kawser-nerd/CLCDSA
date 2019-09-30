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
    int n, k;
    cin >> n >> k;

    vector<vector<vector<double>>> dp(
        n + 1, vector<vector<double>>(k + 1, vector<double>(2)));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int b = 0; b <= 1; b++) {
                if (i == 0) {
                    dp[i][j][b] = b ? 1 : 0;
                    continue;
                }

                int ate = n - i;
                double p = 1.0 * ate / (ate + 1);
                double ans = 0;
                ans += p * dp[i - 1][j][b];
                ans += (1 - p) * max(dp[i - 1][j][0], j == 0 ? 0 : dp[i - 1][j - 1][1]);

                dp[i][j][b] = ans;
            }
        }
    }

    cout << fixed << setprecision(9) << dp[n][k][0] << endl;

    return 0;
}