#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) std::cerr<< #x <<": "<<x<<"\n"
#define debug2(x,y) std::cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<"\n"
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<bool> db;
template<class T> using vv=vector<vector< T > >;

// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size(); s << "\n";
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  s << "\n"; return s;
}

// cout 2-dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) { s << vv[i]; }
  return s;
}

typedef std::multimap<string, string> mss;
typedef std::pair<string, string> pss;
vector<pss> calc(string r) {
  int n = r.length();
  int m = (1 << n);
  vector<pss> ret(m);;
  rep (i, m) {
    string s = "";
    string t = "";
    rep (j, n) {
      if (((i >> j) & 1) == 1) {
        s += r[j];
      } else {
        t += r[j];
      }
    }
    reverse(all(t));
    ret[i] = (pss){s, t};
  }
  sort(all(ret));
  return ret;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = s.substr(0, n);
  string u = s.substr(n, n);
  auto mapt = calc(t);
  auto mapu = calc(u);
  ll cnt = 0;
  for (auto p : mapt) {
    auto lb = lower_bound(all(mapu), (pss){p.second, p.first});
    auto ub = upper_bound(all(mapu), (pss){p.second, p.first});
    cnt += (ub - lb);
  }
  printf("%lld\n", cnt);

  return 0;
}