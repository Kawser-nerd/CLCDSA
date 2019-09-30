#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int T; cin >> T;
  int X, S, R, N;
  double trun;
  for(int t = 1; t <= T; t++) {
    cin >> X >> S >> R >> trun >> N;
    vector<pair<int, int> > V;
    for(int i = 0; i < N; i++) {
      int a, b, w; cin >> a >> b >> w;
      V.push_back(make_pair(w, b - a));
      X -= b - a;
    }
    V.push_back(make_pair(0, X));
    sort(V.begin(), V.end());

    double tm = 0;
    for(int i = 0; i < V.size(); i++) {
      double x = V[i].second;
      double w = V[i].first;
      while(x > 1e-9) {
        double tr = min((R + w) * trun, x);
        if(tr) {
          double dt = tr / (R + w);
          tm += dt;
          trun -= dt;
          x -= tr;
        } else {
          tm += x / (S + w);
          x = 0;
        }
      }
    }

    printf("Case #%d: %.9f\n", t, tm);
  }
}
