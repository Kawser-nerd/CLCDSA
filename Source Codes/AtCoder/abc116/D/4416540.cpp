#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;

using P = pair<int, long>;

int main() {
  int N, K;
  cin >> N >> K;
  vector<P> td(N);
  for (int i{}; i < N; ++i) {
    int t, d;
    cin >> t >> d;
    td[i] = P{t, d};
  }
  sort(td.begin(), td.end(), [](P l, P r) {
    return l.second > r.second;
  });

  map<int, vector<long >> choice;
  long point{};
  int type{};
  for (int i{}; i < K; ++i) {
    choice[td[i].first].push_back(td[i].second);
    point += td[i].second;
  }
  type = choice.size();
  point += type * type;

  for (auto &p : choice) {
    auto &v = p.second;
    if (v.size() > 1)
      sort(v.begin(), v.end(), greater<long>());
  }

  int alt{K};
  long ans{point};
  for (int i{K - 1}; i >= 0; --i) {
    int t = td[i].first;
    int d = td[i].second;
    if (choice[t].size() == 1)
      continue;
    while (alt < N) {
      int nt = td[alt].first;
      int nd = td[alt].second;
      ++alt;
      if (choice.find(nt) == choice.end()) {
        point += (nd - d) + ((type + 1) * (type + 1) - type * type);
        if (ans < point) {
          ans = point;
        }
        assert(choice[t].back() == d);
        choice[t].pop_back();
        choice[nt].push_back(nd);
        ++type;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}