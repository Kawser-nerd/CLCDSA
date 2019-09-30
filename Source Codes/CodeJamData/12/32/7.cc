#include <cstdio>
#include <cmath>

double t[2005], x[2005];

int main() {

    int T, test;

    scanf("%d", &T);

    for (int test = 1; test <= T; test++) {
        double d;
        int n, m;

        scanf("%lf %d %d", &d, &n, &m);
        int last = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &t[i], &x[i]);
            if (x[i] >= d && !last) {
                t[i] = t[i-1] + ((t[i] - t[i-1]) / (x[i] - x[i-1])) * (d - x[i-1]);
                x[i] = d;
                last = i;
            }
        }
        printf("Case #%d:\n", test);
        for (int i = 0; i < m; i++) {
            double a;
            scanf("%lf", &a);
            
            double l = 0.0, r = t[last];
//            printf("%d, a = %.2lf, r = %.2lf\n", test, a, r);
            double ans = 0;
            for (int j = 0; j < 60; j++) {
                double mid = (l+r)/2.0;

                int k;
                for (k = 1; k <= last; k++) {
                    if (t[k] <= mid) continue;
                    if (sqrt(x[k] * 2.0 / a) + mid < t[k]) break;
                }
                if (k <= last) l = mid;
                else {
                    r = mid;
                    ans = sqrt(d * 2.0 / a) + mid;
                }
            }
//            printf("r = %.2lf\n", r);
            printf("%.7lf\n", ans);
        }
    }

    return 0;
}
