#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;

int isVertex(int x, int y, int H, int *xs, int *ys, int *hs, int N) {
  for (int i=0; i<N; i++) {
    if (hs[i] != max(H - abs(xs[i] - x) - abs(ys[i] - y), 0)) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int N;
  cin >> N;
  int x[N], y[N], h[N];
  int x1, y1, h1 = 0;
  for (int i=0; i<N; i++) {
    cin >> x[i] >> y[i] >> h[i];
    if (h1 == 0 && h[i] > 0) {
      h1 = h[i];
      x1 = x[i];
      y1 = y[i];
    }
  }
  
  for (int xv=0;xv<=100;xv++) {
    for (int yv=0;yv<=100;yv++) {
      int hv = abs(x1 - xv) + abs(y1 - yv) + h1;

      if (isVertex(xv, yv, hv, x, y, h, N)) {
        cout << xv << " " << yv << " " << hv << endl;
      }
    }
  }

  return 0;
}