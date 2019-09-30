#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstdio>

using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int D, N;
    cin >> D >> N;

    double res = 0;
    for (int i = 0; i < N; i++) {
      int K, S;
      cin >> K >> S;

      res = max(res, 1.0 * (D - K) / S);
    }

    cout << "Case #" << t << ": ";
    printf("%.9f\n", D / res);
  }
  return 0;
}
