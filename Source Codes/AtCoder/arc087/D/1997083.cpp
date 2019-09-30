#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <cassert>
#include <map>
#include <iostream>
#include <set>
using namespace std;

const int MOD = 1e9 + 7;

const int N = 5000001;
long long fact[N];
long long invfact[N];
long long inv[N];
void init() {
        fact[0] = fact[1] = 1;
        for (int i = 2; i < N; i ++) fact[i] = fact[i - 1] * i % MOD;
        inv[1] = 1;
        for (int i = 2; i < N; i ++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        invfact[0] = invfact[1] = 1;
        for (int i = 2; i < N; i ++) invfact[i] = invfact[i - 1] * inv[i] % MOD;
}
long long C(long long n, long long r) {
        if (n < 0 || r < 0 || n < r) return 0;
        return fact[n] * invfact[n - r] % MOD * invfact[r] % MOD;
}

vector<int> Centroid(int root, const vector<vector<int>> &g, const vector<bool> &dead) {
        int alive_cnt = 0;
        map<int, int> alive_node;
        //{
                function<void (int, int)> count_alive = [&](int u, int prev) {
                        alive_node[u] = alive_cnt ++;
                        for (auto v : g[u]) if (v != prev && !dead[v]) {
                                count_alive(v, u);
                        }
                };
                count_alive(root, -1);
        //}
        vector<int> centroid;
        vector<int> sz(alive_cnt);
        function<void (int, int)> dfs = [&](int u, int prev) {
                int x = alive_node[u];
                sz[x] = 1;
                bool is_centroid = true;
                for (auto v : g[u]) if (v != prev && !dead[v]) {
                        dfs(v, u);
                        int y = alive_node[v];
                        sz[x] += sz[y];
                        if (sz[y] > alive_cnt / 2) is_centroid = false;
                }
                if (alive_cnt - sz[x] > alive_cnt / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(root, -1);
        return centroid;
}

int main() {
        init();
        int n;
        scanf("%d", &n);
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i ++) {
                int a, b;
                scanf("%d%d", &a, &b);
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        vector<bool> dead(n);
        auto get = Centroid(0, g, dead);
        if (get.size() == 2) {
                long long ans = fact[n / 2] * fact[n / 2] % MOD;
                printf("%lld\n", ans);
                return 0;
        } else if (get.size() == 1) {
                int centroid = get[0];
                vector<int> sz(n);
                function<void (int, int)> get_size = [&](int u, int prev) {
                        sz[u] = 1;
                        for (auto v : g[u]) if (v != prev) {
                                get_size(v, u);
                                sz[u] += sz[v];
                        }
                };
                get_size(centroid, -1);
                vector<int> subtrees;
                for (auto v : g[centroid]) subtrees.push_back(sz[v]);
                int k = (int) subtrees.size();
                vector<vector<long long>> dp(k + 1, vector<long long> (n + 1, 0));
                dp[0][1] = 1;
                for (int i = 0; i < k; i ++) {
                        int num = subtrees[i];
                        for (int j = 0; j <= n - num; j ++) {
                                for (int l = 0; l <= num; l ++) {
                                        if (l & 1) {
                                                (dp[i + 1][j + num - l] -= dp[i][j] * C(num, l) % MOD * fact[num] % MOD * invfact[num - l] % MOD) %= MOD;
                                        } else {
                                                (dp[i + 1][j + num - l] += dp[i][j] * C(num, l) % MOD * fact[num] % MOD * invfact[num - l] % MOD) %= MOD;
                                        }
                                }
                        }
                }
                long long ans = 0;
                for (int i = 0; i <= n; i ++) {
                        (ans += dp[k][i] * fact[i] % MOD) %= MOD;
                }
                ans = ((ans % MOD) + MOD) % MOD;
                printf("%lld\n", ans);
        } else {
                printf("%d\n", 1 << 20);
        }
        return 0;
}