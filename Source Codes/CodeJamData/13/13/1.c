#include <stdio.h>

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int r, n, m, k, x, y, z, j, l, p;
        
        printf("Case #%d:\n", i + 1);
        
        scanf("%d %d %d %d", &r, &n, &m, &k);
        
        for (j = 0; j < r; j++) {
            int a[7];
            
            for (l = 0; l < k; l++) scanf("%d", &a[l]);
            
            for (x = 2; x <= m; x++) {
                for (y = x; y <= m; y++) {
                    for (z = y; z <= m; z++) {
                        for (l = 0; l < k; l++) {
                            for (p = 0; p < 8; p++) {
                                int w = 1;
                                
                                if (p & 1) w *= x;
                                if (p & 2) w *= y;
                                if (p & 4) w *= z;
                                
                                if (w == a[l]) break;
                            }
                            
                            if (p == 8) break;
                        }
                        
                        if (l == k) {
                            printf("%d%d%d\n", x, y, z);
                            
                            break;
                        }
                    }
                    
                    if (z <= m) break;
                }
                
                if (y <= m) break;
            }
        }
    }
    
    return 0;
}
