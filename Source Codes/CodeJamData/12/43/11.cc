#include <cstring>
#include <iostream>
using namespace std;

int peak[10000], h[10000], impossible;

void doit(int a, int b, int x1, int y1, int x2, int y2) {
  assert(a <= b);
  if (a == b) return;
  for (int c = a; c < b; c++) if (peak[c] > b) impossible = true;
  if (impossible) return;

  bool strict = false;
  int last = a;
  for (int c = a; c < b; c++) if (peak[c] == b) {
    h[c] = (y2-y1)*(long long)(c-x1)/(x2-x1);
    while (h[c]*(long long)(x2-x1) > (y2-y1)*(long long)(c-x1))
      h[c]--;
    if (strict && h[c]*(long long)(x2-x1) == (y2-y1)*(long long)(c-x1))
      h[c]--;
    h[c] += y1;
    if (h[c] < 0) {impossible = true; return;}
    x1 = c; y1 = h[c];
    x2 = b; y2 = h[b];
    strict = true;
    doit(last, c, x1, y1, x2, y2);
    if (impossible) return;
    last = c+1;
  }
  assert(last == b);
}

main() {
  int T, N, prob=1;
  for (cin >> T; T--;) {
    cin >> N;
    impossible = false;
    for (int i = 0; i+1 < N; i++) {cin >> peak[i]; peak[i]--;}
    memset(h, -1, sizeof(h));
    h[N-1] = 1000000000;
    doit(0, N-1, 0, 1000000000, N-1, 1000000000);
    if (impossible) {
      cout << "Case #" << prob++ << ": Impossible" << endl;
    } else {
      cout << "Case #" << prob++ << ":";
      for (int i = 0; i < N; i++) cout << ' ' << h[i];
      cout << endl;
    }
  }
}
