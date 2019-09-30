#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
int main(int argc, char const *argv[]) {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  double ans = 0;
  ll ans_sugar = 0;
  ll ans_water = 0;
  for (int a = 0; a <= 30; a++) {
    if (a * A * 100 > F) continue;
    for (int b = 0; b <= 30; b++) {
      if (b * B * 100 > F || (b * B + a * A) * 100 > F) continue;
      for (int c = 0; c < 3001; c++) {
        if (c * C > F) continue;
        for (int d = 0; d < 3001; d++) {
          if (a + b + c + d == 0) continue;
          if (d * D > F) continue;
          if (ans < (double)100 * (C * c + D * d) /
                        (A * a * 100 + B * b * 100 + C * c + D * d) &&
              (double)100 * (C * c + D * d) /
                      (A * a * 100 + B * b * 100 + C * c + D * d) <=
                  (double)100 * E / (100 + E) &&
              (A * a + B * b) * 100 + C * c + D * d <= F) {
            ans = (double)100 * (C * c + D * d) /
                  (A * a * 100 + B * b * 100 + C * c + D * d);
            ans_sugar = C * c + D * d;
            ans_water = (A * a + B * b) * 100;
            //cout << "e;"
              //   << (double)100 * (C * c + D * d) /
                //        (A * a * 100 + B * b * 100 + C * c + D * d)<<"limit_density"<<(double)E*100/(100+E)<<endl;
          }
        }
      }
    }
  }
  if(ans_water==0){printf("%d %d",min(F,min(A*100,B*100)),0);
  return 0;}
  printf("%lld %lld\n", ans_water + ans_sugar, ans_sugar);

  return 0;
}