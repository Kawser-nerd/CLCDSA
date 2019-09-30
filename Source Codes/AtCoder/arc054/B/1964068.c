#include <stdio.h>
#include <math.h>

double f(double x, double p) {
  return x + pow(2, -x/1.5)*p;
}

int main() {
  double p;
  scanf("%lf", &p);

  double lb=0, midl, midu, ub=1e42;
  double phi=(1+sqrt(5))/2;
  for (int i=0; i<250; ++i) {
    midl = (phi*lb + ub) / (phi+1);
    midu = (lb + phi*ub) / (phi+1);

    if (f(midl, p) > f(midu, p)) {
      lb = midl;
      midl = midu;
    } else {
      ub = midu;
      midu = midl;
    }
  }

  printf("%.12f\n \n \n", f(lb, p));
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf", &p);
   ^