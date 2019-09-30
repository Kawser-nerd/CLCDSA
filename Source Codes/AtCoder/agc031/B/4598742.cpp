#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int MOD = 1e9+7;
vector <int> idx[200005];
int dp[200005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int c[n];
    vector <int> prev(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        int sz = idx[c[i]].size();
        if (sz) prev[i] = idx[c[i]][sz - 1];
        idx[c[i]].push_back(i);
    }

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i-1];

        if (c[i] != c[i-1] && prev[i] != -1) {
            (dp[i] += dp[prev[i]]) %= MOD;
        }
    }

    cout << dp[n-1] << "\n";
    return 0;
}