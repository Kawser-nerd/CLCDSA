#include <stdio.h>
#include <math.h>

double len(int x1, int y1, int x2, int y2) {
    double xl = (double)x1 - (double)x2;
    double yl = (double)y1 - (double)y2;
    return sqrt(pow(xl,2.0) + pow(yl,2.0));
}

int main() {
    int ax, ay, bx, by, t, v; scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &t, &v);
    int n; scanf("%d", &n);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        double cost = len(ax, ay, x, y) + len(bx, by, x, y);
        if (cost <= (double)t * v) flag = 1;
    }
    puts(flag ? "YES" : "NO");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:31: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int ax, ay, bx, by, t, v; scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &t, &v);
                               ^
./Main.c:12:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int n; scanf("%d", &n);
            ^
./Main.c:15:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         int x, y; scanf("%d%d", &x, &y);
                   ^