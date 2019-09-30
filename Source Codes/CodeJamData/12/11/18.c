#include <stdio.h>

double min(double a, double b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int t, i, j;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int a, b;
        double c = 1, ans;
        
        scanf("%d %d", &a, &b);

        ans = b + 2;
        
        for (j = 0; j < a; j++) {
            double p;
            
            scanf("%lf", &p);
            
            ans = min(ans, c * (a + b - 2 * j + 1) + (1 - c) * (a + 2 * b - 2 * j + 2));

            c *= p;
        }
        
        ans = min(ans, c * (b - j + 1) + (1 - c) * (2 * b - j + 2));
        
        printf("Case #%d: %lf\n", i + 1, ans);
    }
    
    return 0;
}
