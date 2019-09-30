#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>
using namespace std;

#define FOR(i,a,n) for(int i = (a); i < (n); ++i)
#define REP(i,n) FOR(i,0,n)
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using P = pair<int,int>;
vector<P> R;
vector<P> B;

int main() {
  int n; cin >> n;
  int a, b, c, d;
  R.resize(n); B.resize(n);
  REP(i, n) {
    cin >> a >> b;
    R[i] = make_pair(a,b);
  }
  REP(i, n) {
    cin >> c >> d;
    B[i] = make_pair(c,d);
  }
  whole(sort,R);
  whole(sort,B);
  int r = 0;
  b = 0;
  set<int> S;
  int ans = 0;
  REP(i, 2*n) {
    if (r < n && (b >= n || R[r].first < B[b].first)) {
      S.insert(R[r].second);
      r++;
    } else {
      int r = 0;
      for (int y = B[b].second; y >= 0 && r == 0; y--) {
        r = S.erase(y);
      }
      ans += r;
      b++;
    }
  }
  cout << ans << endl;
  return 0;
}