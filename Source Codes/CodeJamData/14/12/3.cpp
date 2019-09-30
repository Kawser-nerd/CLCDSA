#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a[1024];

void read() {
    for (int i = 0; i < 1024; i++) a[i].clear();
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y;
        
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

int dfs(int x, int par) {
    int ans = 1;
    vector<int> b;
    
    for (int i = 0; i < (int)a[x].size(); i++) {
        if (a[x][i] != par) {
            b.push_back(dfs(a[x][i], x));
        }
    }
    sort(b.rbegin(), b.rend());
    
    if ((int)b.size() > 1) {
        ans = b[0] + b[1] + 1;
    }
    
    return ans;
}

void solve() {
    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dfs(i, -1));
//        printf ("%d %d\n", i, ans);
    }
    
    printf ("%d\n", n - ans);
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
