#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define rep(n, i) for(int i = 0; i < n; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define INF 100000000000

double find_max(double* a, int n){
    double temp_max = a[0];
    rep(n-1, i) temp_max = MAX(temp_max, a[i+1]);
    return temp_max;
}
double find_min(double* a, int n){
    double temp_min = a[0];
    rep(n-1, i) temp_min = MIN(temp_min, a[i+1]);
    return temp_min;
}
double bin_search(double max_t, double min_t, double* xs, double* ys, double* cs, int n, int counter){
    double mid_t = (max_t + min_t) / 2;
    if (counter == 0) return mid_t;
    double xleft = -100000, xright = 100000, yleft = -100000, yright = 100000;
    rep(n, i){
        xleft  = MAX(xleft, xs[i] - mid_t/cs[i]);
        xright = MIN(xright, xs[i] + mid_t/cs[i]);
        yleft  = MAX(yleft, ys[i] - mid_t/cs[i]);
        yright = MIN(yright, ys[i] + mid_t/cs[i]);
    }

    if ((xleft <= xright) && (yleft <= yright)) return bin_search(mid_t, min_t, xs, ys, cs, n, counter-1);
    else return bin_search(max_t, mid_t, xs, ys, cs, n, counter-1);
}


void solve(void){
    int n;
    scanf("%d\n", &n);
    double xs[n], ys[n], cs[n];
    rep(n, i) scanf("%lf %lf %lf\n", &xs[i], &ys[i], &cs[i]);

  printf("%lf\n", bin_search(INF, 0, xs, ys, cs, n, 64));
}

int main(void){
  solve();
  return 0;
} ./Main.c: In function ‘solve’:
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n", &n);
     ^
./Main.c:40:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     rep(n, i) scanf("%lf %lf %lf\n", &xs[i], &ys[i], &cs[i]);
               ^