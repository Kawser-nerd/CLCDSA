#include <stdio.h>

int max(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int t, i, j, k;
    int a[10000][2];
    int b[10000];
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, d, f = 0;
        
        scanf("%d", &n);
        
        for (j = 0; j < n; j++) scanf("%d %d", &a[j][0], &a[j][1]);
        
        scanf("%d", &d);
        
        for (j = 0; j < n; j++) b[j] = 0;
        
        b[0] = a[0][0];
        
        for (j = 0; j < n; j++) {
            if (a[j][0] + b[j] >= d) {
                f = 1;
                
                break;
            }
            
            for (k = j + 1; k < n; k++) {
                if (a[j][0] + b[j] < a[k][0]) break;
                
                b[k] = max(b[k], min(a[k][0] - a[j][0], a[k][1]));
            }
        }
        
        if (f == 1) {
            printf("Case #%d: YES\n", i + 1);
        } else {
            printf("Case #%d: NO\n", i + 1);
        }
    }
    
    return 0;
}
