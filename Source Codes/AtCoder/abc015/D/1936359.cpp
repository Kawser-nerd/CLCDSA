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
    int w;
    cin >> w;

    int n, k;
    cin >> n >> k;

    vector<int> ws(n);
    vector<int> vs(n);
    for (int i = 0; i < n; i++) {
        cin >> ws[i] >> vs[i];
    }

    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(k + 1, vector<int>(w + 1)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= w; l++) {
                int ans = dp[i - 1][j][l];
                if (l >= ws[i - 1]) {
                    ans = max(ans, dp[i-1][j-1][l-ws[i-1]] + vs[i-1]);
                }
                dp[i][j][l] = ans;
            }
        }
    }

    cout << dp[n][k][w] << endl;
    return 0;
}