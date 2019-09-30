#include <iostream>
#include <set>
using namespace std;

using P = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  set<P> requests;
  for (int i{}; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    requests.insert(P{a, b});
  }

  int ans{1};
  P wp{1, N};
  for (const auto &r : requests) {
    P p{max(wp.first, r.first), min(wp.second, r.second)};
    if (p.first < p.second) {
      wp = p;
    } else {
      ++ans;
      wp = r;
    }
  }

  cout << ans << endl;
  return 0;
}