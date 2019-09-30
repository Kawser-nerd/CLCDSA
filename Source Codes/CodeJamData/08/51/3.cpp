#include <stdio.h>

int n;
char str[50];
int k;

int lo[6001], hi[6001];
int x, y, x1, y1, px, py;
long long area;

void exec (char f) {
    px = x;
    py = y;
    if (f == 'F') {
        x += x1;
        y += y1;
        }
    else
        if (f == 'L') {
            int xx = x1, yy = y1;
            
            x1 = yy;
            y1 = -xx;
            }
        else {
            int xx = x1, yy = y1;
            
            x1 = -yy;
            y1 = xx;
            }
    lo[x] <?= y;
    hi[x] >?= y;
    
    area += x * py - y * px;
    }

int main () {
    int t, i, j, l;
    int ct = 0;
    
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d", &n);
        
        x = 3000;
        y = 3000;
        x1 = 1;
        y1 = 0;
        area = 0;
        
        for (i = 0; i <= 6000; i ++) {
            lo[i] = 10000;
            hi[i] = -1;
            }
        for (i = 0; i < n; i ++) {
            scanf("%s%d", str, &k);
            for (j = 0; j < k; j ++)
                for (l = 0; str[l]; l ++)
                    exec(str[l]);
            }
        if (area < 0)
            area = - area;
        area /= 2;
        
        int ll = 10000, hh = -1, beg, end;
        
        for (i = 0; i <= 6000; i ++) {
            ll <?= lo[i];
            hh >?= hi[i];
            }
        beg = 6000; end = 0;
        for (i = 0; i <= 6000; i ++)
            if (lo[i] == ll) {
                beg <?= i;
                end >?= i;
                }
        for (i = beg; i <= end; i ++)
            lo[i] = ll;
        for (i = beg - 1; i >= 0; i --)
            for (j = 0; j < i; j ++)
                lo[i] <?= lo[j];
        for (i = end + 1; i <= 6000; i ++)
            for (j = i + 1; j <= 6000; j ++)
                lo[i] <?= lo[j];
        beg = 6000; end = 0;
        for (i = 0; i <= 6000; i ++)
            if (hi[i] == hh) {
                beg <?= i;
                end >?= i;
                }
        for (i = beg; i <= end; i ++)
            hi[i] = hh;
        for (i = beg - 1; i >= 0; i --)
            for (j = 0; j < i; j ++)
                hi[i] >?= hi[j];
        for (i = end + 1; i <= 6000; i ++)
            for (j = i + 1; j <= 6000; j ++)
                hi[i] >?= hi[j];
        
        beg = 0;
        while (lo[beg] == 10000)
            beg ++;
        end = 6000;
        while (lo[end] == 10000)
            end --;
        
        for (i = beg; i <= end; i ++)
            area -= hi[i] - lo[i];
        area += hh - ll;
        
        printf("Case #%d: %I64d\n", ++ ct, -area);
        }
    
    return 0;
    }
