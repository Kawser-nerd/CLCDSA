#include <cmath>
#include <iostream>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
  int x[3],y[3];
  REP(i,3) cin >> x[i] >> y[i];

  // ??????
  double a = sqrt(pow(x[0] - x[1], 2.0) + pow(y[0] - y[1], 2.0));
  double b = sqrt(pow(x[1] - x[2], 2.0) + pow(y[1] - y[2], 2.0));
  double c = sqrt(pow(x[2] - x[0], 2.0) + pow(y[2] - y[0], 2.0));
  double s = (a+b+c)/2.0;

  printf("%.3f\n",sqrt(s*(s-a)*(s-b)*(s-c)));
  return 0;
}