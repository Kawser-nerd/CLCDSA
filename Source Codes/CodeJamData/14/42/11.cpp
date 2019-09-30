#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, ans = 0, j, k;
        
        scanf("%d", &n);
        
        for (j = 0; j < n; j++) scanf("%d", &a[j]);
        
        for (j = 0; j < n; j++) {
            int x = 1e9 + 1, y = 0, c1 = 0, c2 = 0;
            
            for (k = 0; k < n; k++) {
                if (a[k] < x) {
                    x = a[k];
                    y = k;
                }
            }
            
            for (k = 0; k < y; k++) {
                if (a[k] != 1e9 + 1) c1++;
            }
            
            for (k = y + 1; k < n; k++) {
                if (a[k] != 1e9 + 1) c2++;
            }
            
            ans += min(c1, c2);
            a[y] = 1e9 + 1;
        }
        
        printf("Case #%d: %d\n", i + 1, ans);
    }
    
    return 0;
}
