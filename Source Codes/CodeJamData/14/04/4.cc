#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    int N;
    cin >> N;
    vector<double> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
//for (int i = 0; i < N; i++) cout << a[i] << ' ';
//cout << endl;
//for (int i = 0; i < N; i++) cout << b[i] << ' ';
//cout << endl;
    int ret1 = 0, ret2 = 0;
    for (int ai = N-1, bi = N-1; ai >= 0;) {
      if (a[ai] > b[bi]) {
        ret2++; ai--;
      } else {
        ai--; bi--;
      }
    }
    for (int ai = 0; ai < N; ai++) {
      bool done = true;
      for (int i = ai, j = 0; i < N; i++, j++)
        if (a[i] < b[j]) {done = false; break;}
      if (done) {ret1 = N-ai; break;} 
    }
    cout << "Case #" << prob++ << ": " << ret1 << ' ' << ret2 << endl;
  }
}
