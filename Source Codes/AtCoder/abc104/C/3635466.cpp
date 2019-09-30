#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
  int D;
  ll G;
  cin >> D >> G;
  vector<ll> P(D), C(D);

  for (int i = 0; i < D; i++) {
    cin >> P[i] >> C[i];
  }

  ll res = 1 << 29;
  for (int bit = 0; bit < (1 << D); bit++) {
    ll sum = 0;
    ll num = 0;
    for (int i = 0; i < D; i++) {
      if ((bit >> i) & 1) {
        sum += (i + 1) * 100 * P[i] + C[i];
        num += P[i];
      }
    }
    if (sum >= G)
      res = min(res, num);

    for (int i = D - 1; i >= 0; i--) {
      if ((bit >> i) & 1)
        continue;
      for (int j = 0; j < P[i]; j++) {
        sum += (i + 1) * 100;
        num++;
        if (sum >= G) {
          res = min(res, num);
          break;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}