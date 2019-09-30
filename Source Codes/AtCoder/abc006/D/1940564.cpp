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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        const int ai = a[i];

        int l = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < ai && dp[j] > l) {
                l = dp[j];
            }
        }
        dp[i] = l + 1;
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << n - ans << endl;

    return 0;
}