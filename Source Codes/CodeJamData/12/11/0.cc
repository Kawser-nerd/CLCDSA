#include <cstdio>
#include <iostream>
using namespace std;

double p[100001];

main() {
  int T, A, B, prob = 1;
  for (cin >> T; T--;) {
    cin >> A >> B;
    for (int i = 0; i < A; i++) cin >> p[i];
    double ret = 2+B;
    double pr = 1.0;
    for (int i = 0; i <= A; i++) {
      ret = min(ret, pr * ((A-i)+(B-i)+1) + (1-pr) * ((A-i)+(B-i)+1+B+1));
      pr *= p[i];
    }
    printf("Case #%d: %.10lf\n", prob++, ret);
  }
}
