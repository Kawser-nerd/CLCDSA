#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

constexpr int MOD = 1e9+7;
using graph = vector<vector<int>>;

// c == 1: white
int dfs(graph const& g, int i, int p, int c, vector<vector<int>>& dp) {
    int& r = dp[i][c];
    if(r != -1) {
        return r;
    }
    r = 1;
    for(auto v : g[i]) {
        if(v != p) {
            ll cnt = dfs(g, v, i, 1, dp);
            if(c == 1) {
                cnt += dfs(g, v, i, 0, dp);
            }
            cnt %= MOD;
            r = ((ll)r * cnt) % MOD;
        }
    }
    return r;
}

int main() {
    int N;
    cin >> N;
    graph g(N);
    for(int i=0; i<N-1; ++i) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<vector<int>> dp(N, vector<int>(2, -1));
    cout << (dfs(g, 0, -1, 1, dp) + dfs(g, 0, -1, 0, dp)) % MOD << endl;
}