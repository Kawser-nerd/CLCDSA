#include <stdio.h>

int n, m, a;
int r1, r2;

int test (int x) {
    if (x == 0) {
        r1 = r2 = 0;
        return 1;
        }
    int i;
    
    for (i = (x + m - 1) / m; i <= n; i ++)
        if (x % i == 0 && x / i <= m) {
            r1 = i;
            r2 = x / i;
            return 1;
            }
    return 0;
    }

int main () {
    int t, ct, i;
    
    ct = 0;
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d%d%d", &n, &m, &a);
        i = 0;
        while (i + a <= n * m && (!test(i) || !test(i + a)))
            i ++;
        if (i + a > n * m)
            printf("Case #%d: IMPOSSIBLE\n", ++ct);
        else {
            int a1,a2,a3,a4;
            test(i);
            a1 = r1;
            a2 = r2;
            test(i + a);
            a3 = r1;
            a4 = r2;
            printf("Case #%d: %d %d %d %d %d %d\n", ++ct, 0, 0, a3, a2, a1, a4);
            }
        }
    
    return 0;
    }
