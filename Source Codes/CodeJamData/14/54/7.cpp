#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n;
int a[128];
vector<int> b[128];

void read() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        b[i].clear();
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        b[x].push_back(i);
        b[i].push_back(x);
    }
}

int lvl[128];
int lca[128][128];
int par[128];

void dfs(int x, int p = -1) {
    par[x] = p;
    for (int i = 0; i < (int)b[x].size(); i++) {
        if (b[x][i] != p) {
            lvl[ b[x][i] ] = lvl[x] + 1;
            dfs(b[x][i], x);
        }
    }
}

int dp[82][82][82][82][2];
int u[82][82][82][82][2];

int onpath(int s, int e, int r) {
    if (lvl[ lca[s][e] ] <= lvl[r] && lca[s][r] == r) return 1;
    if (lvl[ lca[s][e] ] <= lvl[r] && lca[e][r] == r) return 1;
    return 0;
}

int go(int s1, int e1, int s2, int e2, int t) {
    int &ans = dp[s1][e1][s2][e2][t];
    if (u[s1][e1][s2][e2][t]) return ans;
    u[s1][e1][s2][e2][t] = 1;
    
    ans = -(1 << 30);
    int went = 0;
    
  //  printf ("here\n");
    
    for (int i = 0; i < (int)b[e1].size(); i++) {
        int r = b[e1][i];
        int win = a[r];
        
        if (onpath(s1, e1, e1) && onpath(s1, e1, r)) continue;
        if (onpath(s2, e2, e1) && onpath(s2, e2, r)) continue;
        
        if (onpath(s1, e1, r) || onpath(s2, e2, r)) win = 0;
        
        went = 1;
        ans = max(ans, -go(s2, e2, s1, r, 0) + win);
    }
    if (!went && !t) {
        ans = max(ans, -go(s2, e2, s1, e1, 1));
    }
    if (!went && t) return ans = 0;
    
  //  printf ("%d %d   %d %d   %d\n", s1, e1, s2, e2, ans);
    
    return ans;
}

void solve() {
    int ans = -(1 << 30);
    
    lvl[1] = 0;
    dfs(1);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x = i;
            int y = j;
            
            while (x != y) {
                if (lvl[x] >= lvl[y]) x = par[x];
                else y = par[y];
            }
            
            lca[i][j] = x;
        }
    }
    
    memset(u, 0, sizeof u);
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++) {
        int cur = 1 << 30;
        
        for (int j = 1; j <= n; j++) {
    //        printf ("%d %d\n", i, j);
            cur = min(cur, go(i, i, j, j, 0) + a[i] - (i != j) * a[j]);
        }
        ans = max(ans, cur);
    }
    
    printf ("%d\n", ans);
}

int main() {
    int cases;
    
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++) {
        read();
        printf ("Case #%d: ", i);
        solve();
  //      return 0;
    }
    
    return 0;
}
