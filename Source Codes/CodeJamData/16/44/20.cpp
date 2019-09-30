#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

const int MAXN = 25;
const int INF = MAXN * MAXN;

vector<int> adj[MAXN + MAXN];
bool mark[MAXN + MAXN];

void flood(int u, int n, int &a, int &b)
{
    if (u < n) {
        ++ a;
    } else {
        ++ b;
    }
    mark[u] = true;
    for (int i = 0; i < adj[u].size(); ++ i) {
        int v = adj[u][i];
        if (!mark[v]) {
            flood(v, n, a, b);
        }
    }
}

map<vector<int>, int> memo;
vector<pair<int, int>> distinct;

int dfs(vector<int> cnt);

int dfs(vector<int> &cnt, int i, int a, int b)
{
    int maxi = 0, mini = 0;
    for (int j = i; j < cnt.size(); ++ j) {
        int delta = distinct[j].first - distinct[j].second;
        if (delta > 0) {
            maxi += delta * cnt[j];
        } else {
            mini += delta * cnt[j];
        }
    }
    if (a - b + maxi < 0 || a - b + mini > 0) {
        return INF;
    }
    if (i == cnt.size()) {
        if (a > 0) {
            return a * a + dfs(cnt);
        } else {
            return INF;
        }
    }
    int ret = INF;
    for (int x = 0; x <= cnt[i]; ++ x) {
        cnt[i] -= x;
        ret = min(ret, dfs(cnt, i + 1, a + x * distinct[i].first, b + x * distinct[i].second));
        cnt[i] += x;
    }
    return ret;
}

int dfs(vector<int> cnt)
{
    if (memo.count(cnt)) {
        return memo[cnt];
    }
    int s = 0;
    for (int i = 0; i < cnt.size(); ++ i) {
        s += cnt[i];
    }
    if (s == 0) {
        return 0;
    }
    return memo[cnt] = dfs(cnt, 0, 0, 0);
}

int solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n + n; ++ i) {
        adj[i].clear();
    }
    int already = 0;
    for (int i = 0; i < n; ++ i) {
        char s[MAXN + 1];
        scanf("%s", s);
        for (int j = 0; j < n; ++ j) {
            if (s[j] == '1') {
                ++ already;
                adj[i].push_back(n + j);
                adj[n + j].push_back(i);
            }
        }
    }
    int base = 0;
    vector<pair<int, int>> comp;
    memset(mark, false, sizeof(mark));
    for (int i = 0; i < n + n; ++ i) {
        if (!mark[i]) {
            int a = 0, b = 0;
            flood(i, n, a, b);
            if (a == b) {
                base += a * b;
            } else {
                comp.push_back(make_pair(a, b));
            }
        }
    }
    sort(comp.begin(), comp.end());
    distinct = comp;
    distinct.erase(unique(distinct.begin(), distinct.end()), distinct.end());
    vector<int> cnt(distinct.size(), 0);
    fprintf(stderr, "distinct = %d\n", distinct.size());
    for (int i = 0; i < comp.size(); ++ i) {
        ++ cnt[lower_bound(distinct.begin(), distinct.end(), comp[i]) - distinct.begin()];
    }
    memo.clear();
    int answer = dfs(cnt);

    return base + answer - already;
}

int main()
{
    int test = 1, tests;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        printf("Case #%d: %d\n", test, solve());
    }
    return 0;
}
