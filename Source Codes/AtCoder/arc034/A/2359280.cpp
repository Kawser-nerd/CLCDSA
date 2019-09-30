#include <cstdio>
#include <algorithm>

using namespace std;

int main () {

    int n;
    scanf("%d", &n);

    int a[n], b[n], c[n], d[n], e[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d", &a[i], &b[i], &c[i], &d[i], &e[i]);
    }

    double max_score = a[0] + b[0] + c[0] + d[0] + (double)e[0] * 110.0 / 900;
    for (int i = 1; i < n; i++) {
        double cur_score = a[i] + b[i] + c[i] + d[i] + (double)e[i] * 110.0 / 900;
        max_score = max(cur_score, max_score);
    }
    printf("%.16lf\n", max_score);

    return 0;
}