#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

double dist(double x1, double y1, double x2, double y2){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double getsqr(double r1, double r2, double d){
  double a1 = (d*d + r1*r1 - r2*r2) / (2*d*r1);
  if (a1 > 1) a1 = 1;
  if (a1 < -1) a1 = -1;
  a1 = acos(a1);
  double res = r1*r1*a1;
  double res2 = r1*r1*cos(a1)*sin(a1);
  return res - res2;
}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int tn;
  scanf("%d", &tn);
  for (int t=1; t<=tn; t++){
    printf("Case #%d:", t);
    int n, m;
    scanf("%d%d", &n, &m);
    double px[5010], py[5010];
    for (int i=0; i<n; i++){
      scanf("%lf%lf", &px[i], &py[i]);
    }
    for (int j=0; j<m; j++){
      double qx, qy;
      scanf("%lf%lf", &qx, &qy);
      double r1 = dist(px[0], py[0], qx, qy);
      double r2 = dist(px[1], py[1], qx, qy);
      double d = dist(px[0], py[0], px[1], py[1]);
      double ans = 0;
      ans += getsqr(r1, r2, d);
      ans += getsqr(r2, r1, d);
      printf(" %.10lf", ans);
    }
    printf("\n");
  }
  return 0;
}
