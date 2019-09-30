#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int vd[10010], vl[10010], bestd[10010];

main() {
  int T, N, prob=1;
  for (cin >> T; T--;) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> vd[i] >> vl[i];
    cin >> vd[N];
    memset(bestd, 63, sizeof(bestd));
    bestd[0] = 0;

    for (int i = 0; i < N; i++) if (bestd[i] < vd[i]) {
      int mx = vd[i] + min(vl[i], vd[i]-bestd[i]);
      for (int j = i+1; j <= N && vd[j] <= mx; j++)
        bestd[j] = min(bestd[j], vd[i]);
    }
    cout << "Case #" << prob++ << ": ";
    if (bestd[N] < vd[N]) cout << "YES" << endl; else cout << "NO" << endl;
  }
}
