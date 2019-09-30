#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
 
typedef long long ll;
 
constexpr int MAX_N = 400200;
constexpr int MOD = 1000000007;
 
using namespace std;
 
int n, x, y;
int col[MAX_N], weight[MAX_N];
 
vector<pair<int, int>> each[MAX_N];
vector<pair<int, int>> all;
 
vector<int> adj[MAX_N];
bool vis[MAX_N];
 
int dfs(int u, unordered_map<int, int> &col_cnt) {
    if (vis[u]) return 0;
    vis[u] = true;
    int ans = 1;
    col_cnt[col[u]]++;
    for (int v : adj[u]) {
        ans += dfs(v, col_cnt);
    }
    return ans;
}
 
int fact(int x) {
    ll ans = 1;
    for (int i = 1; i <= x; i++) {
        ans = (ans * i) % MOD;
    }
    return ans;
}
 
int pow(int b, int e) {
    if (e == 0) return 1;
    ll res = pow(b, e >> 1);
    res = (res * res) % MOD;
    if (e & 1) res = (res * b) % MOD;
    return res;
}
 
int inv(int x) {
    return pow(x, MOD - 2);
}
 
int permute(int cnt, unordered_map<int, int> &col_cnt) {
    ll ans = fact(cnt);
    for (pair<int, int> c : col_cnt) {
        if (c.second > 0) {
            ans = (ans * inv(fact(c.second))) % MOD;
        }
    }
    return ans;
}
 
int main() {
    scanf(" %d %d %d", &n, &x, &y);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &col[i], &weight[i]);
        each[col[i]].push_back(make_pair(weight[i], i));
        all.push_back(make_pair(weight[i], i));
    }
 
    sort(all.begin(), all.end());
    for (int i = 1; i <= n; i++) {
        sort(each[i].begin(), each[i].end());
    }
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < each[i].size(); j++) {
            if (each[i][j].first + each[i][0].first <= x) {
                adj[each[i][j - 1].second].push_back(each[i][j].second);
                adj[each[i][j].second].push_back(each[i][j - 1].second);
            }
        }
    }

    int diff = n;
    for (int i = 1; i < all.size(); i++) {
        if (col[all[i].second] != col[all[i - 1].second]) {
            diff = i;
            break;
        }
    }

    int bases[] = { 0, diff };
 
    for (int i = 1; i < all.size(); i++) {
        for (int j = 0; j < 2; j++) {
            if (col[all[i].second] == col[all[bases[j]].second]) continue;
            if (all[i].first + all[bases[j]].first > y) continue;
            adj[all[i].second].push_back(all[bases[j]].second);
            adj[all[bases[j]].second].push_back(all[i].second);
        }
    }
 
    ll tot = 1;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            unordered_map<int, int> col_cnt;
            int cnt = dfs(i, col_cnt);
            tot = (tot * (ll) permute(cnt, col_cnt)) % MOD;
        }
    }
 
    printf("%lld\n", tot);
 
    return 0;
}