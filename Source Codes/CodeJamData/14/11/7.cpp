#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int ca = 1; ca <= T; ++ca) {
    int N, L;
    cin >> N >> L;
    vector<string> out(N), dev(N);
    for (int i = 0; i < N; ++i) {
      cin >> out[i];
    }
    for (int i = 0; i < N; ++i) {
      cin >> dev[i];
    }
    sort(dev.begin(), dev.end());
    
    int best = -1;
    for (int fo = 0; fo < N; ++fo) {
      vector<bool> flip(L, false);
      int cnt = 0;
      for (int i = 0; i < L; ++i) {
        if (dev[0][i] != out[fo][i]) {
          flip[i] = true;
          ++cnt;
        }
      }
      if (best == -1 || cnt < best) {
        vector<string> out2 = out;
        for (int i = 0; i < N; ++i) {
          for (int j = 0; j < L; ++j) {
            if (flip[j]) {
              if (out2[i][j] == '0') out2[i][j] = '1';
              else out2[i][j] = '0';
            }
          }
        }
        sort(out2.begin(), out2.end());
        bool ok = true;
        for (int i = 0; i < N; ++i) {
          if (dev[i] != out2[i]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          best = cnt;
        }
      }
    }
    cout << "Case #" << ca << ": ";
    if (best == -1) cout << "NOT POSSIBLE" << endl;
    else cout << best << endl;
  }
}

