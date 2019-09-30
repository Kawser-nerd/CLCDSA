#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cstdlib>
#include <utility>

using namespace std;

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    double C, F, X;
    cin >> C >> F >> X;

    double R = 2;
    double tm = 0;
    double res = 1e300;
    for(int num = 0; ; num++) {
      double nval = tm + X / R;
      if(nval > res) {
        break;
      }
      res = nval;
      tm += C / R;
      R += F;
    }
    printf("Case #%d: %.9f\n", t, res);
  }
  return 0;
}
