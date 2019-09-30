#include <stdio.h>

int n;
int x1,x2;
int y1,y2;
int xx[1000], yy[1000], p;

int main () {
    
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    
    int t, ct = 0;
    
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d", &n);
        
        x1 = y1 = 2147483647;
        x2 = y2 = -2147483647;
        p = 0;
        
        for (int i = 0; i < n; i ++) {
            char buf[100];
            int a, b;
            
            scanf("%d%d", &a, &b);
            fgets(buf, 100, stdin);

            if (buf[1] == 'B') {
                x1 <?= a;
                x2 >?= a;
                y1 <?= b;
                y2 >?= b;
                }
            else {
                xx[p] = a;
                yy[p] = b;
                p ++;
                }
            }
        
        scanf("%d", &n);
        printf("Case #%d:\n", ++ ct);
        for (int i = 0; i < n; i ++) {
            int a, b;
            
            scanf("%d%d", &a, &b);
            if (a >= x1 && a <= x2 && b >= y1 && b <= y2)
                printf("BIRD\n");
            else {
                int f = 1;
                for (int j = 0; j < p && f; j ++) {
                    int f2 = 1;
                    if (xx[j] < x1 && a > xx[j])
                        f2 = 0;
                    if (xx[j] > x2 && a < xx[j])
                        f2 = 0;
                    if (yy[j] < y1 && b > yy[j])
                        f2 = 0;
                    if (yy[j] > y2 && b < yy[j])
                        f2 = 0;
                    if (f2)
                        f = 0;
                    }
                if (f)
                    printf("UNKNOWN\n");
                else
                    printf("NOT BIRD\n");
                }
            }
        }
    
    return 0;
    }
