#include <algorithm>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

/* -------------------------------- Template -------------------------------- */

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

template<typename T> T inf;
template<> constexpr int inf<int> = 1e9;
template<> constexpr ll inf<ll> = 1e18;
template<> constexpr ld inf<ld> = 1e30;

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

/* -------------------------------- Library -------------------------------- */

/* ---------------------------------- Main ---------------------------------- */

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha;
  cout.imbue(loc);

  int n; cin >> n;
  vector<int> up(n), down(n);
  REP(i, n) { cin >> up[i]; }
  REP(i, n) { cin >> down[i]; }

  vector<int> dpu(n), dpd(n);
  dpu[0] = up[0];
  dpd[0] = up[0] + down[0];
  REP(i, n-1){
    dpu[i + 1] = dpu[i] + up[i + 1];
    dpd[i + 1] = max(dpu[i + 1], dpd[i]) + down[i + 1];
  }

  cout << dpd[n - 1] << endl;
  return 0;
}