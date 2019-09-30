#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;
#define print(var) cout << setprecision(2) << var << endl

int main() {
  double xa, ya, xb, yb, xc, yc;
  double ans;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  xb -= xa;
  xc -= xa;
  yb -= ya;
  yc -= ya;
  ans = abs(xb * yc - xc * yb) / 2.0;
  cout << fixed << setprecision(3) << ans << endl;
}