#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int sx[10000], sy[10000], su[10000];

main() {
  int T, N, W, L, prob=1;
  for (cin >> T; T--;) {
    cin >> N >> W >> L;
    vector<pair<int, int> > R(N);
    for (int i = 0; i < N; i++) {
      cin >> R[i].first;
      R[i].second = i;
    }
    sort(R.begin(), R.end());
    memset(su, 0, sizeof(su));
    int x = -R[N-1].first;
    for (int i = N-1; i >= 0; i--) if (!su[R[i].second]) {
      x += R[i].first;
      assert(x <= W);
      sx[R[i].second] = x; sy[R[i].second] = 0;
      su[R[i].second] = true;
      int y = R[i].first;
      for (int j = i-1; j >= 0; j--) if (!su[R[j].second] && y+R[j].first <= L) {
        y += R[j].first;
        sx[R[j].second] = x; sy[R[j].second] = y;
        su[R[j].second] = true;
        y += R[j].first;
      }
      x += R[i].first;
    }
    cout << "Case #" << prob++ << ":";
    for (int i = 0; i < N; i++) cout << ' ' << sx[i] << ' ' << sy[i];
    cout << endl;
  }
}
