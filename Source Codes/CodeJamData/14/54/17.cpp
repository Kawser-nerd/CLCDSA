#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[80];
vector <int> v[80];
vector <int> w;

int get(int x, int y, int z)
{
    int i;
    
    if (x == z) {
        w.push_back(x);
        
        return 1;
    }
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        if (get(v[x][i], x, z) == 1) {
            w.push_back(x);
            
            return 1;
        }
    }
    
    return 0;
}

int dfs2(int x, int y)
{
    int ans = 0, i;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        ans = max(ans, dfs2(v[x][i], x));
    }
    
    return ans + a[x];
}

int dfs(int x, int y, int z)
{
    int i, j;
    
    if (x == y) {
        int m1 = 0, m2 = 0;
        
        for (i = 0; i < v[w[x]].size(); i++) {
            int c;
            
            if (x > 0 && v[w[x]][i] == w[x - 1]) continue;
            if (y < w.size() - 1 && v[w[x]][i] == w[y + 1]) continue;
            
            c = dfs2(v[w[x]][i], w[x]);
            
            if (c > m1) {
                m2 = m1;
                m1 = c;
            } else if (c > m2) {
                m2 = c;
            }
        }
        
        if (z == 0) {
            return m1 - m2;
        } else {
            return m2 - m1;
        }
    }
    
    if (z == 0) {
        int ans = dfs(x + 1, y, 1);
        int m1 = 0, m2 = 0, m = 0, p = 0;
        
        if (x + 1 != y) ans += a[w[x + 1]];
        
        for (i = 0; i < v[w[x]].size(); i++) {
            int c;
            
            if (x > 0 && v[w[x]][i] == w[x - 1]) continue;
            if (v[w[x]][i] == w[x + 1]) continue;
            
            c = dfs2(v[w[x]][i], w[x]);
            
            if (c > m1) {
                m2 = m1;
                m1 = c;
            } else if (c > m2) {
                m2 = c;
            }
        }
        
        for (i = y; i > x; i--) {
            int tmp = 0;
            
            if (i < y) p += a[w[i]];
            
            for (j = 0; j < v[w[i]].size(); j++) {
                if (v[w[i]][j] == w[i - 1]) continue;
                if (i < w.size() - 1 && v[w[i]][j] == w[i + 1]) continue;
                
                tmp = max(tmp, dfs2(v[w[i]][j], w[i]));
            }
            
            m = max(m, tmp + p);
        }
        
        m = max(m, m2 + p);
        
        ans = max(ans, m1 - m);
        
        return ans;
    } else {
        int ans = dfs(x, y - 1, 0);
        int m1 = 0, m2 = 0, m = 0, p = 0;
        
        if (x != y - 1) ans -= a[w[y - 1]];
        
        for (i = 0; i < v[w[y]].size(); i++) {
            int c;
            
            if (v[w[y]][i] == w[y - 1]) continue;
            if (y < w.size() - 1 && v[w[y]][i] == w[y + 1]) continue;
            
            c = dfs2(v[w[y]][i], w[y]);
            
            if (c > m1) {
                m2 = m1;
                m1 = c;
            } else if (c > m2) {
                m2 = c;
            }
        }
        
        for (i = x; i < y; i++) {
            int tmp = 0;
            
            if (i > x) p += a[w[i]];
            
            for (j = 0; j < v[w[i]].size(); j++) {
                if (i > 0 && v[w[i]][j] == w[i - 1]) continue;
                if (v[w[i]][j] == w[i + 1]) continue;
                
                tmp = max(tmp, dfs2(v[w[i]][j], w[i]));
            }
            
            m = max(m, tmp + p);
        }
        
        m = max(m, m2 + p);
        
        ans = min(ans, m - m1);
        
        return ans;
    }
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, ans = -1e9, j, k;
        
        scanf("%d", &n);
        
        for (j = 0; j < n; j++) v[j].clear();
        
        for (j = 0; j < n; j++) scanf("%d", &a[j]);
        
        for (j = 0; j < n - 1; j++) {
            int x;
            
            scanf("%d", &x);
            
            x--;
            
            v[j].push_back(x);
            v[x].push_back(j);
        }
        
        for (j = 0; j < n; j++) {
            int tmp = 1e9;
            
            for (k = 0; k < n; k++) {
                w.clear();
                
                get(j, -1, k);
                
                reverse(w.begin(), w.end());
                
                if (j == k) {
                    tmp = min(tmp, dfs(0, w.size() - 1, 0) + a[j]);
                } else {
                    tmp = min(tmp, dfs(0, w.size() - 1, 0) + a[j] - a[k]);
                }
            }
            
            ans = max(ans, tmp);
        }
        
        printf("Case #%d: %d\n", i + 1, ans);
    }
    
    return 0;
}
