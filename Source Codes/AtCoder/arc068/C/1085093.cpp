#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int N, M;
vector<P> R[100001];

struct BIT {
  int n; vector<int> xs;
  BIT(int n) : n(n) {
    xs.resize(n+1);
  }

  void add(int x, int k) {
    for (int i=x+1; i<=n; i+=i&-i) xs[i] += k;
  }
  int sum(int x) {
    int s = 0;
    for (int i=x+1; i>0; i-=i&-i) s += xs[i];
    return s;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M;
  BIT bit(M+1);
  for (int i=0; i<N; i++) {
    int l, r;
    cin >> l >> r;
    R[r-l+1].push_back(P(l, r));
  }

  int s = N;
  for (int d=1; d<=M; d++) {
    s -= R[d-1].size();
    for (auto &p : R[d-1]) {
      bit.add(p.first, 1);
      bit.add(p.second+1, -1);
    }
    int c = 0;
    for (int i=d; i<=M; i+=d) c += bit.sum(i);
    cout << s + c << "\n";
  }
  return 0;
}