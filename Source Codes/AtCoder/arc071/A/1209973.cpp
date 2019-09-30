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

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep (i, n) {
    cin >> s[i];
  }
  vvi mp(n, vi(26, 0));
  rep (i, n) {
    rep (j, (int)s[i].length()) {
      mp[i][s[i][j] - 'a'] += 1;
    }
  }
  vi ans(26, 100);
  rep (i, 26) {
    rep (j, n) {
      ans[i] = min(ans[i], mp[j][i]);
    }
  }
  rep (i, 26) {
    rep (j, ans[i]) {
      printf("%c", 'a' + i);
    }
  }
  printf("\n");



  return 0;
}