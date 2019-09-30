#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> P;
struct UF {
  vector<int> u;
  vector<int> r;
  UF(int n) {
    for (int i=0; i<n; i++) {
      u.push_back(i);
      r.push_back(1);
    }
  }

  int find(int x) {
    if (u[x] == x) return x;
    return u[x] = find(u[x]);
  }

  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (r[x] < r[y]) swap(x, y);
    u[y] = x;
    r[x] += r[y];
    r[y] = 0;
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int N, K, L;

int main() {
  cin >> N >> K >> L;
  UF x(N), y(N);
  for (int i=0; i<K; i++) {
    int a, b;
    cin >> a >> b;
    x.unite(a-1, b-1);
  }
  for (int i=0; i<L; i++) {
    int a, b;
    cin >> a >> b;
    y.unite(a-1, b-1);
  }

  map<P, int> m;
  for (int i=0; i<N; i++) {
    m[P(x.find(i), y.find(i))]++;
  }
  for (int i=0; i<N; i++) {
    cout << m[P(x.find(i), y.find(i))] << (i==N-1?"\n":" ");
  }
  return 0;
}