//
// Created by Tetsuya Shiota on 2019-04-13.
//

#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define REP(i, b, n) for (Int i = b; i < Int(n); i++)
#define rep(i, n) REP(i, 0, n)
#define FOR(e, o) for (auto &&e : o)
#ifdef LOCAL
#define pp(x) cout << __LINE__ << ' ' << #x << " = " << (x) << endl
#define dump(x)                                                                \
  cout << __LINE__ << ' ' << #x << " : ";                                      \
  FOR(e, x) cout << e << ' ';                                                  \
  cout << endl;
#else
#define pp(x)
#define dump(x)
#endif

using namespace std;

using Int = long long;
using vi = vector<Int>;
using vvi = vector<vi>;
using pii = pair<Int, Int>;

template <typename T> void reverse(vector<T> &v) {
  reverse(v.begin(), v.end());
}

template <typename T> void sort(vector<T> &v) { sort(v.begin(), v.end()); }
template <typename T> void rsort(vector<T> &v) { sort(v.rbegin(), v.rend()); }

template <typename T> T sum(const vector<T> &v) {
  return accumulate(v.begin(), v.end(), T(0));
}

template <class T> void update_max(T &a, const T &b) { a = max(a, b); }
template <class T> bool update_min(T &a, const T &b) { a = min(a, b); }

struct BoolName : numpunct<char> {
  string t, f;
  BoolName(string t = "Yes", string f = "No") : t(t), f(f) {}
  string do_truename() const { return t; }
  string do_falsename() const { return f; }
};

class Solver {
public:
  Solver() {}
  vi ans = {-1, -1, -1};
  int N, Y;
  void input() {
    cin >> N >> Y;
    pp(N);
  }
  void solve() {
    rep(i, N + 1) {
      rep(j, N + 1) {
        int now = 0, k = (N - i - j);
        if (k < 0)
          break;
        now += i * 10000;
        now += j * 5000;
        now += k * 1000;
        if (Y == now) {
          ans = {i, j, k};
          dump(ans);
          return;
        }
      }
    }
  }
  void output() { cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl; }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(15) << boolalpha;
  cout.imbue(locale(cout.getloc(), new BoolName));
#ifdef LOCAL
  while (1) {
    Solver s;
    s.input();
    if (cin.eof())
      break;
    s.solve();
    s.output();
  }
#else
  Solver s;
  s.input();
  s.solve();
  s.output();
#endif
}