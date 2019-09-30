#include <stdio.h>
static int n, m, x, y, a[100000], b[100000], ia, ib, t, sum;
int main(void) {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (ia = 0; ia < n; ++ia) scanf("%d", a + ia);
    for (ib = 0; ib < m; ++ib) scanf("%d", b + ib);
    ia = ib = 0;
    while (1) {
        while (a[ia] < t) {
            ++ia;
            if (ia >= n) goto end;
        }
        if (ia >= n) goto end;
        t = a[ia++];
        t += x;
        
        while (b[ib] < t) {
            ++ib;
            if (ib >= m) goto end;
        }
        if (ib >= m) goto end;
        t = b[ib++];
        t += y;
        
        ++sum;
    }
end:
    printf("%d\n", sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d", &n, &m, &x, &y);
     ^
./Main.c:5:32: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (ia = 0; ia < n; ++ia) scanf("%d", a + ia);
                                ^
./Main.c:6:32: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (ib = 0; ib < m; ++ib) scanf("%d", b + ib);
                                ^