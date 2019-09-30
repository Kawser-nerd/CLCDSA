#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[701];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, x, ans = 0, j, k;
        
        scanf("%d %d", &n, &x);
        
        for (j = 0; j <= x; j++) a[j] = 0;
        
        for (j = 0; j < n; j++) {
            int p;
            
            scanf("%d", &p);
            
            a[p]++;
        }
        
        for (j = x; j >= 0; j--) {
            if (a[j] == 0) continue;
            
            ans++;
            a[j]--;
            
            for (k = j; k >= 0; k--) {
                if (a[k] > 0 && j + k <= x) {
                    a[k]--;
                    break;
                }
            }
            
            j++;
        }
        
        printf("Case #%d: %d\n", i + 1, ans);
    }
    
    return 0;
}
