#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int p, q, n;
int h[128], g[128];

int dp[102][1002][202];

void read() {
    scanf("%d%d%d", &p, &q, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &h[i], &g[i]);
    }
}

int go(int x, int y, int he) {
    if (x == n + 1) return 0;
    if (he < 1) {
        return go(x + 1, y, h[x + 1]);
    }
    int &ans = dp[x][y][he];
    if (ans != -1) return ans;
    
    ans = 0;
    if (y) {
        ans = max(ans, go(x, y - 1, he - p) + g[x] * ((he - p) < 1));
    }
    
    ans = max(ans, go(x, y + 1, he - q));
    
    if (he - p < 1) {
        ans = max(ans, go(x + 1, y, h[x + 1] - q) + g[x]);
    } else {
        ans = max(ans, go(x, y, he - p - q));
    }
    
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    printf ("%d\n", go(1, 0, h[1]));
}

int main() {
    int cases;
    
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++) {
        read();
        printf ("Case #%d: ", i);
        solve();
    }
    
    return 0;
}
