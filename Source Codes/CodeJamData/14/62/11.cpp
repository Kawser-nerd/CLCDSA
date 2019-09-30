#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[1 << 12];
long long fact[13];

long long dfs(int x, int y)
{
    int i, j, k;
    long long ans = 0;
    
    if (x == n) {
        for (i = 0; i < (1 << n); i++) {
            if (a[i] != i) return 0;
        }
        
        return fact[y];
    }
    
    for (i = 0; i < (1 << n); i += (1 << (x + 1))) {
        if (a[i] % (1 << (x + 1)) != 0) {
            if (a[i + (1 << x)] % (1 << (x + 1)) != 0) {
                for (j = 0; j < (1 << n); j += (1 << (x + 1))) {
                    if (a[j] == a[i] - a[i] % (1 << (x + 1))) {
                        if (a[j + (1 << x)] != a[j + (1 << x)] - a[j + (1 << x)] % (1 << (x + 1))) return 0;
                        
                        for (k = 0; k < (1 << x); k++) swap(a[i + k], a[j + (1 << x) + k]);
                        
                        ans += dfs(x + 1, y + 1);
                        
                        for (k = 0; k < (1 << x); k++) swap(a[i + k], a[j + (1 << x) + k]);
                        
                        return ans;
                    }
                }
                
                return 0;
            } else {
                for (k = 0; k < (1 << x); k++) swap(a[i + k], a[i + (1 << x) + k]);
                
                ans += dfs(x + 1, y + 1);
                
                for (k = 0; k < (1 << x); k++) swap(a[i + k], a[i + (1 << x) + k]);
                
                return ans;
            }
        } else if (a[i + (1 << x)] != a[i] + (1 << x)) {
            for (j = 0; j < (1 << n); j += (1 << x)) {
                if (a[j] == a[i] + (1 << x)) {
                    for (k = 0; k < (1 << x); k++) swap(a[i + (1 << x) + k], a[j + k]);
                    
                    ans += dfs(x + 1, y + 1);
                    
                    for (k = 0; k < (1 << x); k++) swap(a[i + (1 << x) + k], a[j + k]);
                    
                    if (j % (1 << (x + 1)) != 0) {
                        for (k = 0; k < (1 << x); k++) swap(a[i + k], a[j - (1 << x) + k]);
                        
                        ans += dfs(x + 1, y + 1);
                        
                        for (k = 0; k < (1 << x); k++) swap(a[i + k], a[j - (1 << x) + k]);
                    }
                    
                    return ans;
                }
            }
            
            return 0;
        }
    }
    
    return dfs(x + 1, y);
}

int main()
{
    int t, i;
    
    fact[0] = 1;
    
    for (i = 1; i <= 12; i++) fact[i] = fact[i - 1] * i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int j;
        long long ans;
        
        scanf("%d", &n);
        
        for (j = 0; j < (1 << n); j++) {
            scanf("%d", &a[j]);
            
            a[j]--;
        }
        
        ans = dfs(0, 0);
        
        printf("Case #%d: %lld\n", i + 1, ans);
    }
    
    return 0;
}
