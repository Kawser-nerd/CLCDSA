#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

#define double long double
typedef pair<int, int> P;

int N, Q;
P R[200000];
double fact[200001];

struct BIT {
  int n;
  vector<double> xs;
  BIT (int n) : n(n) {
    xs.resize(n+1);
  }
  void add(int i, double v) {
    for (int x=i+1; x<=n; x+=x&-x) xs[x] += v;
  }
  double sum(int i) {
    if (i >= n) i = n-1;
    double s = 0;
    for (int x=i+1; x>0; x-=x&-x) s += xs[x];
    return s;
  }
  double sum(int a, int b) {
    return sum(b) - sum(a-1);
  }
};

int main() {
  cin >> N;
  for (int i=0; i<N; i++) {
    int p, q;
    cin >> p >> q;
    R[i] = P(p, q);
  }

  fact[0] = 0;
  for (int i=2; i<=200000; i++) {
    fact[i] = fact[i-1] + log(i);
  }

  BIT bit(N-1);
  for (int i=0; i<N-1; i++) {
    int dx = R[i+1].first-R[i].first, dy = R[i+1].second-R[i].second;
    bit.add(i, fact[dx+dy] - fact[dx] - fact[dy]);
  }

  cin >> Q;
  for (int i=0; i<Q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int k, a, b;
      cin >> k >> a >> b;
      k--;
      R[k] = P(a, b);

      for (int i=k-1; i<=k; i++) {
        if (i < 0 || i+1 >= N-1) continue;
        int nx = R[i+1].first, ny = R[i+1].second;
        int x = R[i].first, y = R[i].second;
        int dx = nx-x, dy = ny - y;
        bit.add(i, -bit.sum(i, i));
        bit.add(i, fact[dx+dy] - fact[dx] - fact[dy]);
      }
    }
    else {
      int l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      l1--, r1--, l2--, r2--;
      double a = bit.sum(l1, r1-1),
             b = bit.sum(l2, r2-1);
      if (a >= b) cout << "FIRST\n";
      else cout << "SECOND\n";
    }
  }
  return 0;
}