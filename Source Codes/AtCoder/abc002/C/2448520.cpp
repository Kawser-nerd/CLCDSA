#include <iostream>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
  int x[3],y[3];
  REP(i,3) cin >> x[i] >> y[i];

  double ans = ((x[0] - x[1])*(y[2] - y[1]) -
                (y[0] - y[1])*(x[2] - x[1])) * 0.5;
  printf("%.2f\n", ((ans < 0) ? -ans : ans));
  return 0;
}