#include <algorithm>
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

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n);
    for (int i = 1; i < n; i++) {
        dp[i] = a[i - 1] < a[i] ? dp[i - 1] + 1 : 0;
    }

    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += dp[i];
    }
    cout << sum + n << endl;

    return 0;
}