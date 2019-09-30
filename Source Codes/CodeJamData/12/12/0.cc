#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int ai[1001], bi[1001], done[1001];

main() {
  int T, N, prob=1;
  for (cin >> T; T--;) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> ai[i] >> bi[i];

    memset(done, 0, sizeof(done));
    int stars = 0, ret = 0;
    while (stars < 2*N) {
      int best1 = -1;
      for (int i = 0; i < N; i++) if (done[i] < 2 && bi[i] <= stars) {
        ret++;
        stars += 2-done[i];
        done[i] = 2;
        goto played;
      }
      for (int i = 0; i < N; i++) if (done[i] < 1 && ai[i] <= stars) {
        if (best1 == -1 || bi[i] > bi[best1])
          best1 = i;
      }
      if (best1 == -1) {
        cout << "Case #" << prob++ << ": Too Bad" << endl;
        goto done;
      }
      ret++;
      stars += 1-done[best1];
      done[best1] = 1;
played:;
    }
    cout << "Case #" << prob++ << ": " << ret << endl;
done:;
  }
}
