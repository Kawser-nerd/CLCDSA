#include <cstdio>
#include <algorithm>

using namespace std;

char s[2000][2001];
int par[2000];
int par2[2000];
int cnt[2000];
int cnt2[2000];

int find(int *par, int x)
{
    if (par[x] == x) return x;
    
    return par[x] = find(par, par[x]);
}

void unite(int *par, int x, int y)
{
    x = find(par, x);
    y = find(par, y);
    
    if (x == y) return;
    
    par[x] = y;
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, ans = 0, c1 = 0, c2 = 0, j, k;
        
        scanf("%d", &n);
        
        for (j = 0; j < n * 2; j++) scanf("%s", s[j]);
        
        for (j = 0; j < n * 2; j++) par[j] = par2[j] = j;
        
        for (j = 0; j < n * 2; j++) {
            int x = 0, y = 0;
            
            for (k = 0; k < n * 2; k++) {
                if (s[j][k] == '1') x++;
                if (s[k][j] == '1') y++;
            }
            
            if (x != n || y != n) break;
            
            x = -1;
            y = -1;
            
            for (k = 0; k < n * 2; k++) {
                if (s[j][k] == '1') {
                    if (x != -1) unite(par, x, k);
                    
                    x = k;
                }
                
                if (s[k][j] == '1') {
                    if (y != -1) unite(par2, y, k);
                    
                    y = k;
                }
            }
        }
        
        if (j < n * 2) {
            printf("Case #%d: IMPOSSIBLE\n", i + 1);
            
            continue;
        }
        
        for (j = 0; j < n * 2; j++) cnt[j] = cnt2[j] = 0;
        
        for (j = 0; j < n * 2; j++) {
            cnt[find(par, j)]++;
            cnt2[find(par2, j)]++;
        }
        
        for (j = 0; j < n * 2; j++) {
            if (cnt[j] != 0 && cnt[j] != n) break;
            if (cnt2[j] != 0 && cnt2[j] != n) break;
        }
        
        if (j < n * 2) {
            printf("Case #%d: IMPOSSIBLE\n", i + 1);
            
            continue;
        }
        
        for (j = 0; j < n * 2; j++) {
            if (s[j][0] == '1' && j % 2 == 0) c1++;
            if (s[0][j] == '1' && j % 2 == 0) c2++;
        }
        
        ans += min(c1, n - c1);
        ans += min(c2, n - c2);
        
        printf("Case #%d: %d\n", i + 1, ans);
    }
    
    return 0;
}
