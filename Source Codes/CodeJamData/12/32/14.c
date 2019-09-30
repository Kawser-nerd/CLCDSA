#include <stdio.h>
#include <math.h>

double d, a, t[2001], x[2001];
double speed;
double time;

double check(int i) {
    double lt = 0;
    if (i == 0) {
        lt = sqrt(x[i] * 2 / a);
        speed = lt * a;
    }
    else {
        double mt = (sqrt(speed*speed+2*a*(x[i]-x[i-1])) - speed)/a;
        if (mt + time > t[i]) {
            lt = mt, speed = speed + a * mt;
            //printf("<<< %lf %lf %lf\n", mt, time, t[i]);
        }
        else {
            lt = t[i] - time, speed = (x[i]-x[i-1])/(t[i]-t[i-1]);
            //printf("<<< lt: %lf %lf %lf\n", lt, time, t[i]);
        }
    }
    //printf("<<lt: %lf\n", lt);
    return lt;
}

int main() {
    int tn, t0=0, n, na, i, k;
    scanf("%d", &tn);
    while (tn--) {
        scanf("%lf%d%d", &d, &n, &na);
        for (i=0; i<n; i++) {
            scanf("%lf%lf", t+i, x+i);
        }
        printf("Case #%d:\n", ++t0);
        for (k=0; k<na; k++) {
            scanf("%lf", &a);
            //printf("<<%lf %d %lf\n", d, n, sqrt(2*d/a));
            time = 0;
            speed = 0;
            for (i=0; i<n; i++) {
                if (x[i] < d)
                    time += check(i);
                else {
                    if (i == 0) x[i] = d;
                    else {
                        double sp = (x[i] - x[i-1]) / (t[i] - t[i-1]);
                        x[i] = d;
                        t[i] = (x[i]-x[i-1]) / sp + t[i-1];
                    }
                    time += check(i);
                    //printf("<<<time:%lf\n", time);
                    break;
                }
                //printf("<<time:%lf\n", time);
            }
            printf("%.6lf\n", time);
        }
    }
    return 0;
}
