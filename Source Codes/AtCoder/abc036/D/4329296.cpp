#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

const ll MOD = 1000000007LL;
int n;
vector <int> edge[100005];
ll dp[100005][2];

void dfs(int cur, int par) {
    dp[cur][0] = dp[cur][1] = 1;
    for (auto to : edge[cur]) {
        if (to == par) continue;
        dfs(to, cur);
        dp[cur][0] = (dp[to][0] + dp[to][1]) % MOD * dp[cur][0] % MOD;
        dp[cur][1] = dp[cur][1] * dp[to][0] % MOD;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(0, -1);

    cout << (dp[0][0] + dp[0][1]) % MOD << "\n";
    return 0;
}