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
    int n, m;
    cin >> n >> m;

    vector<int> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x] |= 1 << y;
    }

    const int n2 = 1 << n;
    vector<ll> dp(n2);
    dp[0] = 1;
    for (int s = 1; s < n2; s++) {
        for(int u = 0; u < n; u++){
            int u_mask = 1 << u;
            if(!(s & u_mask)){
                continue;
            }
            if(!(g[u] & s)){
                dp[s] += dp[s & ~u_mask];
            }
        }
    }

    cout << dp[n2-1] << endl;

    return 0;
}