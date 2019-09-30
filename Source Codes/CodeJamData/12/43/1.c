#include <stdio.h>

int main()
{
    int t, i, j, k;
    int x[2000];
    int a[2000];
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, f = 0;
        
        scanf("%d", &n);
        
        for (j = 0; j < n - 1; j++) {
            scanf("%d", &x[j]);
            
            x[j]--;
        }
        
        printf("Case #%d:", i + 1);
        
        for (j = 0; j < n - 1; j++) {
            for (k = j + 1; k < x[j]; k++) {
                if (x[k] > x[j]) {
                    f = 1;
                    
                    break;
                }
            }
            
            if (f == 1) break;
        }
        
        if (f == 1) {
            puts(" Impossible");
            
            continue;
        }
        
        for (j = 0; j < n; j++) a[j] = j * 500000;
        
        for (j = 0; j < n - 1; j++) {
            int c;
            
            for (k = x[j] - 1, c = 1; k > j; k--, c++) a[k] -= c;
        }
        
        for (j = 0; j < n; j++) printf(" %d", a[j]);
        
        puts("");
    }
    
    return 0;
}
