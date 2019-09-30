#include <iostream>
#include <vector>
#include <ext/hash_set>
using namespace std;
using namespace __gnu_cxx;

const int maxn = 100;

int t1, n, m, bS, c[maxn], s[maxn], t[maxn];
bool v[maxn];

struct binary {
    int f[3];
} sta;

bool operator==(const binary&a, const binary& b)
{
    return a.f[0] == b.f[0] && a.f[1] == b.f[1] && a.f[2] == b.f[2];
}

struct hashf {
    size_t operator()(const binary &a) const
    {
        return (a.f[0] + 1) * (a.f[1] + 2) * (a.f[2] + 3);
    }
};

hash_set<binary, hashf> h;

bool cmp(int a, int b)
{
    return s[a] > s[b];
}

void dfs(int S, int C, int T)
{
    if (h.find(sta) != h.end()) return;
    h.insert(sta);
    if (S > bS) bS = S;
    if (!T) return;
    if (C > m) C = m;
    for (int i = 1; i <= n + C; ++i)
        if (!v[i] && t[i]) {
            v[i] = true;
            sta.f[i / 30] += 1 << (i % 30);
            dfs(S + s[i], C + c[i], T + t[i] - 1);
            v[i] = false;
            sta.f[i / 30] -= 1 << (i % 30);
            return;
        }
    vector<int> a[3];
    for (int i = 1; i <= n + C; ++i)
        if (!v[i]) a[c[i]].push_back(i);
    for (int i = 0; i < 3; ++i)
        sort(a[i].begin(), a[i].end(), cmp);
    int tS = S;
    for (int i = 0; i < a[0].size() && i < T; ++i)
        tS += s[a[0][i]];
    if (tS > bS) bS = tS;
    int x = 0, y = 0;
    if (a[1].empty() && a[2].empty()) return;
    if (a[1].empty()) x = a[2][0];
    else
    if (a[2].empty()) x = a[1][0];
    else
    if (s[a[2][0]] >= s[a[1][0]]) x = a[2][0];
    else {
        x = a[1][0];
        y = a[2][0];
    }
    if (x) {
        v[x] = true;
        sta.f[x / 30] += 1 << (x % 30);
        dfs(S + s[x], C + c[x], T + t[x] - 1);
        v[x] = false;
        sta.f[x / 30] -= 1 << (x % 30);
    }
    if (y) {
        v[y] = true;
        sta.f[y / 30] += 1 << (y % 30);
        dfs(S + s[y], C + c[y], T + t[y] - 1);
        v[y] = false;
        sta.f[y / 30] -= 1 << (y % 30);
    }
}

int main()
{
    freopen("c2.in", "r", stdin);
    freopen("c2.out", "w", stdout);
    
    cin >> t1;
    for (int t2 = 1; t2 <= t1; ++t2) {
        memset(v, 0, sizeof(v));
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> c[i] >> s[i] >> t[i];
        cin >> m;
        for (int i = 1; i <= m; ++i)
            cin >> c[n + i] >> s[n + i] >> t[n + i];
        bS = 0;
        h.clear();
        memset(sta.f, 0, sizeof(sta.f));
        dfs(0, 0, 1);
        cout << "Case #" << t2 << ": " << bS << endl;
    }
    
    return 0;
}
