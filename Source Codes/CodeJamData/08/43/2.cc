/* GCJ'08
 * Author: Per Austrin
 */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
//#include <string>
//#include <map>
//#include <vector>

using namespace std;
#define dprintf debug && printf
bool debug = false;

void init() {
}

int N;
double x[2000], y[2000], z[2000], p[2000];

bool cando(double pw) {
  
  double lb[4], ub[4];

  for (int i = 0; i < 4; ++i) lb[i] = -1e30, ub[i] = 1e30;

  for (int i = 0; i < N; ++i) {
    lb[0] >?= -pw*p[i] + x[i]+y[i]+z[i];
    ub[0] <?= pw*p[i]  + x[i]+y[i]+z[i]; 
    lb[1] >?= -pw*p[i] + x[i]-y[i]+z[i];
    ub[1] <?= pw*p[i]  + x[i]-y[i]+z[i];
    lb[2] >?= -pw*p[i] + x[i]+y[i]-z[i];
    ub[2] <?= pw*p[i]  + x[i]+y[i]-z[i];
    lb[3] >?= -pw*p[i] + x[i]-y[i]-z[i];
    ub[3] <?= pw*p[i]  + x[i]-y[i]-z[i];
  }

  for (int i = 0; i < 4; ++i) if (lb[i] > ub[i]) return false;
  return true;

}

void solve(int P) {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%lf%lf%lf%lf", x+i, y+i, z+i, p+i);
  }
  double lo = 0, hi = 1e30;
  for (int i = 0; i < 400; ++i) {
    double m = (lo+hi)/2;
    if (cando(m)) hi = m;
    else lo = m;
  }
  printf("Case #%d: %.9lf\n", P, hi);
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}
