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

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  vi cnt_e(n+1, 0);
  FOR (i, 1, n+1) {
    cnt_e[i] = cnt_e[i-1];
    if (s[i-1] == 'E') {
      cnt_e[i] += 1;
    }
  }
  int ans = 1000000;
  rep (i, n) {
    int cnt = 0;
    cnt += (i - cnt_e[i]);
    cnt += (cnt_e[n] - cnt_e[i+1]);
    ans = min(ans, cnt);
  }
  printf("%d\n", ans);

  return 0;
}