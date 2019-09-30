#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

const int maxN = 5010, oo = 23041997;

using namespace std;

#define FORU(i, l, r) for (int i = l; i <= r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPU(i, r) for (int i = 0; i < r; ++i)
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PINT pair < int, int >
#define BIT(x, i) ((x >> i) & 1)
#define NUM_SET_BIT __builtin_popcountll

int f[maxN], x[maxN], g[maxN][maxN], n;
vector < int > adj[maxN];

void dp(int u) {
    FORU(i, 0, x[u]) g[u][i] = oo;
    f[u] = oo; g[u][0] = 0;
    REPU(i, adj[u].size()) {
        int v = adj[u][i]; dp(v);
        if (f[v] == oo) return;
        FORD(j, x[u], 0) {
            int tmp = oo;
            if (j >= f[v])
                tmp = min(tmp, g[u][j - f[v]] + x[v]);
            if (j >= x[v])
                tmp = min(tmp, g[u][j - x[v]] + f[v]);
            g[u][j] = tmp;
        }
    }
    FORU(i, 0, x[u])
        f[u] = min(f[u], g[u][i]);
}

int main() {
    cin >> n;
    FORU(i, 1, n - 1) {
        int p; scanf("%d", &p);
        adj[p].PB(i + 1);
    }
    FORU(i, 1, n) cin >> x[i];
    dp(1);
    if (f[1] != oo) cout << "POSSIBLE";
    else cout << "IMPOSSIBLE";
}