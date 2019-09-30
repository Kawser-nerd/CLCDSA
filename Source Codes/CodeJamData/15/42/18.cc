#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<double, double> P;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<P> Vp;

const double EPS = 1e-6;

bool cmp_cold(P p1, P p2) {
  return p1.second > p2.second;
}

bool cmp_hot(P p1, P p2) {
  return p1.second < p2.second;
}

int main() {
  cout.setf(ios::fixed);
  cout.precision(9);
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int N;
    double V, X;
    cin >> N >> V >> X;
    double max_rate = 0;
    Vp hot, cold;
    for (int i = 0; i < N; ++i) {
      P p;
      cin >> p.first >> p.second;
      if (fabs(p.second - X) <= EPS) {
        max_rate += p.first;
      } else if (p.second < X) {
        cold.push_back(p);
      } else {
        hot.push_back(p);
      }
    }
    sort(cold.begin(), cold.end(), cmp_cold);
    sort(hot.begin(), hot.end(), cmp_hot);
    int hots = hot.size();
    int colds = cold.size();
    int h = 0, c = 0;
    while (h < hots and c < colds) {
      double r0 = cold[c].first;
      double t0 = cold[c].second;
      double r1 = hot[h].first;
      double t1 = hot[h].second;
      if (r0 <= EPS) {
        ++c;
        continue;
      }
      if (r1 <= EPS) {
        ++h;
        continue;
      }
      double x1 = (X*r0 - r0*t0)/(t1 - X);
      double x0 = (X*r1 - r1*t1)/(t0 - X);
      if (x1 <= r1 + EPS) {
        max_rate += r0 + x1;
        cold[c].first -= r0;
        hot[h].first -= x1;
      } else if (x0 <= r0 + EPS) {
        max_rate += x0 + r1;
        cold[c].first -= x0;
        hot[h].first -= r1;
      } else {
        cerr << "ERROR" << endl;
        return 0;
      }
    }
    cout << "Case #" << cas << ": ";
    if (max_rate <= EPS) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << V/max_rate << endl;
    }
  }
}
