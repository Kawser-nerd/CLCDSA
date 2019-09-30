#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    cout << "Case #" << prob++ << ": ";

    int N, L;
    cin >> N >> L;
    vector<string> os(N), ds(N);
    for (int i = 0; i < N; i++) cin >> os[i];
    for (int i = 0; i < N; i++) cin >> ds[i];
    int ret = 1000000;
    sort(ds.begin(), ds.end());
    for (int i = 0; i < N; i++) {
      vector<string> v = os;
      int cur = 0;
      for (int j = 0; j < L; j++) if (v[0][j] != ds[i][j]) {
        for (int k = 0; k < N; k++) v[k][j] ^= 1;
        cur++;
      }
      if (cur >= ret) continue;
      sort(v.begin(), v.end());
      if (v == ds) ret = cur;
    }

    if (ret == 1000000) {
      cout << "NOT POSSIBLE";
    } else {
      cout << ret;
    }
    cout << endl;
  }
}
