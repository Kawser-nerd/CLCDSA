#include <stdio.h>
#define maxh 10007

int n, m, k;
int x[10], y[10];

int hh (int x) {
    int re = 0;
    int y = x;
    while (y) {
        re += y / maxh;
        y /= maxh;
        }
    return re;
    }

int jc (int x) {
    int re;
    int r1, r2;
    
    r1 = 1;
    r2 = 1;
    for (int i = 1; i < maxh; i ++)
        r1 = (r1 * i) % maxh;
    for (int i = 1; i <= x % maxh; i ++)
        r2 = (r2 * i) % maxh;
    
    re = r2;
    for (int i = 1; i <= x / maxh; i ++)
        re = re * r1 % maxh;
    
    return re;
    }

int div (int a, int b) {
    int i;
    
    for (i = 1; i < maxh; i ++)
        if (b * i % maxh == a)
            return i;
    return 0;
    }

int f (int xx, int yy) {
    if (xx == 0 && yy == 0)
        return 1;
    if (xx < 0 || yy < 0)
        return 0;
    if (xx * 2 < yy || yy * 2 < xx)
        return 0;
    if ((xx + yy) % 3)
        return 0;
    int a, b;
    
    a = (xx + yy) / 3;
    b = (yy + yy - xx) / 3;
    
    if (hh(a) - hh(b) - hh(a - b) > 0)
        return 0;
    
    return div(div(jc(a), jc(b)), jc(a - b));
    }

int bitlen (int x) {
    int y = 0;
    while (x) {
        y += x & 1;
        x >>= 1;
        }
    return y;
    }

int main () {
    int t, ct = 0, i, j, px, py;
    
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d%d%d", &n, &m, &k);
        for (i = 0; i < k; i ++)
            scanf("%d%d", x + i, y + i);
        for (i = 0; i < k; i ++)
            for (j = 0; j < k - 1; j ++)
                if (x[j] > x[j + 1]) {
                    x[j] ^= x[j + 1] ^= x[j] ^= x[j + 1];
                    y[j] ^= y[j + 1] ^= y[j] ^= y[j + 1];
                    }
        
        int ans = 0;
        for (i = 0; i < (1 << k); i ++) {
            int tmp = 1;
            
            px = py = 1;
            for (j = 0; j < k; j ++)
                if (i & (1 << j)) {
                    tmp *= f(x[j] - px, y[j] - py);
                    tmp %= maxh;
                    px = x[j];
                    py = y[j];
                    }
            tmp *= f(n - px, m - py);
            tmp %= maxh;
            
            if (bitlen(i) & 1)
                ans = ans + maxh - tmp;
            else
                ans = ans + tmp;
            ans %= maxh;
            }
        printf("Case #%d: %d\n", ++ct, ans);
        }
    
    return 0;
    }
