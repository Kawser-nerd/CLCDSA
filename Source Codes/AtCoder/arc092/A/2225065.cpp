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
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
 
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

int main() {
  int n;
  scanf("%d", &n);
  vi a(n), b(n), c(n), d(n);
  vector<pii> red(n), blue(n);
  rep (i, n) {
    scanf("%d %d", &(red[i].first), &(red[i].second));
  }
  rep (i, n) {
    scanf("%d %d", &(blue[i].first), &(blue[i].second));
  }
  vvi ab(n*2, vi(3, 0));
  rep (i, n) {
    ab[i][0] = red[i].first;
    ab[i][1] = red[i].second;
    ab[i][2] = 0;
  }
  rep (i, n) {
    ab[n+i][0] = blue[i].first;
    ab[n+i][1] = blue[i].second;
    ab[n+i][2] = 1;
  }
  sort(all(ab));

  set<vi> svred;
  int ans = 0;
  rep (i, 2*n) {
    if (ab[i][2] == 0) {
      svred.insert((vi){ab[i][1], ab[i][0]});
      continue;
    }
    auto lb = svred.lower_bound((vi){ab[i][1], 0});
    if (lb == svred.begin()) {
      continue;
    }
    lb--;
    svred.erase(lb);
    ans += 1;
  }
  printf("%d\n", ans);

  return 0;
}