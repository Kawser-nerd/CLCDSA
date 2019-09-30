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

template <class T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
    for (T e : v) {
        os << e << " ";
    }
    return os;
}

int main() {
    int n, m; cin >> n >> m;

    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        f[i]--;
    }

    vector<int> prev(m, n);
    vector<int> next(n);

    next[n - 1] = n;
    prev[f[n - 1]] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        next[i] = min(next[i + 1], prev[f[i]]);
        prev[f[i]] = i;
    }

    vector<int> dp(n + 2);
    vector<int> sum(n + 2);
    dp[n] = 1;
    sum[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = (sum[i + 1] - sum[next[i] + 1] + MOD) % MOD;
        sum[i] = (sum[i + 1] + dp[i]) % MOD;
    }

    cout << dp[0] << endl;

    return 0;
}