#include <bits/stdc++.h>

using namespace std;

const int M = 20200;
const int inf = 100 * M;

string s;
int n;
int D[2][M], H[2][M];

void read() {
  cin >> s;
  n = s.length();
}

void uax(int &a, int b) {
  a = max(a, b);
}

void kill() {
  auto d = D;
  auto h = H;

  for (int t = 0; t < 2; ++t)
    for (int i = 0; i <= n; ++i) {
      d[t][i] = -inf;
    }

  d[0][0] = 0;
  d[1][0] = 0;

  for (char c : s) {
    int x = c == 'C' ? 1 : 0;

    for (int t = 0; t < 2; ++t)
      fill(h[t], h[t] + M, -inf);

    for (int t = 0; t < 2; ++t)
      for (int i = 0; i <= n; ++i)
        if (d[t][i] >= 0) {
          if (i > 0) {
            if (t == x) {
              uax(h[t ^ 1][i - 1], d[t][i] + 10);
            } else {
              uax(h[t ^ 1][i - 1], d[t][i] + 5);
            }
          }
          if (t != x)
            uax(h[t ^ 1][i + 1], d[t][i]);
        }
    
    h[0][0] = h[1][0] = max(h[0][0], h[1][0]);


    swap(d, h);
  }

  cout << max(d[0][0], d[1][0]) << endl;
}


int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    read();
    kill();
    cerr << "Case #" << i << " done.\n";
  }
  return 0;
}
