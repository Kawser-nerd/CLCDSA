#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
#include <complex>
#include <cassert>
using namespace std;
#define PI 3.14159265358979323846264338327950288
#define acos(x) ((x) <= -1 ? acos(-1) : (x) >= 1 ? acos(1) : acos(x))
#define sqr(x) ((x) * (x))
complex <double> pos[2], cnt;
double r1, r2;
int T;
int M, N;
double dist(complex <double> a, complex <double> b) {
   return abs(a - b);
}
int getLoc(complex <double> &c) {
   double x, y;
   scanf("%lf%lf", &x, &y);
   c = complex <double>(x, y);
   return 0;
}
double calc2(double r, double ang) {
   return sqr(r) * (ang - sin(ang)) / 2;
}
double calc(double d, double r1, double r2) {
   double theta1, theta2;
   theta1 = acos((sqr(d) + sqr(r1) - sqr(r2)) / (2 * d * r1)) * 2;
   theta2 = acos((sqr(d) + sqr(r2) - sqr(r1)) / (2 * d * r2)) * 2;
   return calc2(r1, theta1) + calc2(r2, theta2);
}
int main() {
   int i, j;
   int Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d", &N, &M);
      assert(N == 2);
      getLoc(pos[0]);
      getLoc(pos[1]);
      printf("Case #%d:", Case ++);
      while (M --) {
	 getLoc(cnt);
	 r1 = dist(pos[0], cnt);
	 r2 = dist(pos[1], cnt);
	 printf(" %.6lf", calc(dist(pos[0], pos[1]), r1, r2));
      }
      printf("\n");
   }
   return 0;
}

