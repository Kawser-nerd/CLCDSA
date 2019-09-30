#include <algorithm>
#include <complex>
#include <iomanip>
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

/*
int main() {
    string s;
    cin >> s;

    const int n = s.length();

    if (n > 1000) {
        return 0;
    }

    const int BIAS = n;

    vector<vector<int>> dp(n + 1, vector<int>(2 * BIAS + 1, -INF));
    dp[0][0 + BIAS] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = -BIAS; j <= BIAS; j++) {
            if (s[n - i] == 'M') {
                int ans = -INF;
                if (j - 1 >= -BIAS) {
                    ans = max(ans, dp[i - 1][j - 1 + BIAS]);
                }
                if (j + 1 <= BIAS) {
                    ans = max(ans, dp[i - 1][j + 1 + BIAS]);
                }
                dp[i][j + BIAS] = ans;
            } else if (s[n - i] == '+') {
                if (dp[i - 1][j + BIAS] == -INF) {
                    dp[i][j + BIAS] = -INF;
                } else {
                    dp[i][j + BIAS] = dp[i - 1][j + BIAS] + j;
                }
            } else if (s[n - i] == '-') {
                if (dp[i - 1][j + BIAS] == -INF) {
                    dp[i][j + BIAS] = -INF;
                } else {
                    dp[i][j + BIAS] = dp[i - 1][j + BIAS] - j;
                }
            }
        }
    }

    for (int j = -BIAS; j <= BIAS; j++) {
        cout << std::setw(14) << j << " ";
    }
    cout << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = -BIAS; j <= BIAS; j++) {
            cout << std::setw(14) << dp[i][j + BIAS] << " ";
        }
        cout << endl;
    }

    cout << dp[n][0 + BIAS] << endl;

    return 0;
}
*/

int main() {
    string s;
    cin >> s;

    const int n = s.length();

    vector<int> a(n + 1);
    a[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '+') {
            a[i] = a[i + 1] + 1;
        } else if (s[i] == '-') {
            a[i] = a[i + 1] - 1;
        } else {
            a[i] = a[i + 1];
        }
    }

    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'M') {
            b.push_back(a[i]);
        }
    }

    sort(b.begin(), b.end(), std::greater<int>());

    const int m = b.size();

    int sum_head = 0;
    for (int i = 0; i < m / 2; i++) {
        sum_head += b[i];
    }

    int sum_tail = 0;
    for (int i = m / 2; i < m; i++) {
        sum_tail += b[i];
    }

    cout << sum_head - sum_tail << endl;

    return 0;
}