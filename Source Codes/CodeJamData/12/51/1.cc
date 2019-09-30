#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Level {
  int L, P, ind;
  bool operator<(const Level& lv) const {
    int diff = L*lv.P - lv.L*P;
    if (diff) return diff < 0;
    return ind < lv.ind;
  }
};

main() {
  int T, N, prob = 1;
  for (cin >> T; T--;) {
    cin >> N;
    vector<Level> v(N);
    for (int i = 0; i < N; i++) v[i].ind = i;
    for (int i = 0; i < N; i++) cin >> v[i].L;
    for (int i = 0; i < N; i++) cin >> v[i].P;
    sort(v.begin(), v.end());
    cout << "Case #" << prob++ << ":";
    for (int i = 0; i < N; i++) cout << ' ' << v[i].ind;
    cout << endl;
  }
}
