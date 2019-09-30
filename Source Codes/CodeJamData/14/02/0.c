#include <stdio.h>

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        double c, f, x, t = 0, p = 2, ans = 1e9, j;
        
        scanf("%lf %lf %lf", &c, &f, &x);
        
        for (j = 0; j < 100000; j++) {
            if (t + x / p < ans) ans = t + x / p;
            
            t += c / p;
            p += f;
        }
        
        printf("Case #%d: %.12lf\n", i + 1, ans);
    }
    
    return 0;
}
