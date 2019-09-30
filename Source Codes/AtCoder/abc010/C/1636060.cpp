#include <cstdio>
#include <cmath>

int main(){

  double xa, ya, xb, yb;
  double x[1000], y[1000];
  int t, v, n;

  scanf("%lf %lf %lf %lf %d %d", &xa, &ya, &xb, &yb, &t, &v);
  scanf("%d", &n);

  for(int i = 0; i < n; i++)
    scanf("%lf %lf", &x[i], &y[i]);

  for(int i = 0; i < n; i++){
    double dis = sqrt((xa - x[i]) * (xa - x[i]) + (ya - y[i]) * (ya - y[i]))
                + sqrt((xb - x[i]) * (xb - x[i]) + (yb - y[i]) * (yb - y[i]));
    if(dis <= t * v || fabs(dis - t * v) < 1e-9){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}