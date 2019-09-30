#include <cstdio>
#include <cstring>

const double eps = 1e-9;
const int N = 110;

struct point {
    double x, y;
    point(double x = 0,double y = 0) :x(x), y(y){}
    void read() {scanf("%lf%lf", &x, &y);}
} a[N], b[N];
int W, L, U, G;

double calc(double pos) {
    double r1 = 0, r2 = 0, x, y;
    for (int i = 0; i < L; i ++) {
        if (pos < a[i + 1].x + eps) {
            x = pos;
            y = ((a[i+1].y-a[i].y)/(a[i+1].x-a[i].x))*(x-a[i].x)+a[i].y;
            r1 += (a[i].y + y) * (x-a[i].x) * 0.5;
            break;
        } else
            r1 += (a[i].y + a[i+1].y) * (a[i+1].x-a[i].x) * 0.5;
    }
 
    for (int i = 0; i < U; i ++) {
        if (pos < b[i + 1].x + eps) {
            x = pos;
            y = ((b[i+1].y-b[i].y)/(b[i+1].x-b[i].x))*(x-b[i].x)+b[i].y;
            r2 += (b[i].y + y) * (x-b[i].x) * 0.5;
            break;
        } else
            r2 += (b[i].y + b[i+1].y) * (b[i+1].x-b[i].x) * 0.5;
    }
    
    return r2 - r1;
}
int main() {
    int cas = 0, T;
    for (scanf("%d", &T); T--;) {
        scanf("%d%d%d%d", &W, &L, &U, &G);
        for (int i = 0; i < L; i ++)
            a[i].read();
        for (int j = 0; j < U; j ++)
            b[j].read();
            
        double area = calc((double)W);
        printf("Case #%d:\n", ++cas);
        for (int i = 1; i < G; i ++) {
            double need = area * i / G;
            double lo = 0, hi = (double)W, mid;
            for (int j =0 ; j < 50; j ++) {
                mid = (lo + hi) * 0.5;
                if (calc(mid) < need)
                    lo = mid;
                else hi = mid;
            }
            printf("%.10f\n", lo);
        }
    }
    return 0;
}

