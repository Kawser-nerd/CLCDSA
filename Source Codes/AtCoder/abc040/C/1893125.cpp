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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n);
    dp[n - 1] = 0;
    dp[n - 2] = abs(a[n - 1] - a[n - 2]);

    for (int i = n - 3; i >= 0; i--) {
        dp[i] = min(dp[i + 1] + abs(a[i + 1] - a[i]),
                    dp[i + 2] + abs(a[i + 2] - a[i]));
    }

    cout << dp[0] << endl;

    return 0;
}