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

int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1;
  cin >> s2;

  ll ans = 1;
  int i = 0;
  int state = 0;
  if (s1[i] == s2[i]) {
    ans *= 3;
    i += 1;
    state = 1;
  } else {
    ans *= 6;
    i += 2;
    state = 2;
  }
  for ( ; i < n; ) {
    if (state == 1) {
      if (s1[i] == s2[i]) {
        ans = ans * 2 % mod;
        i += 1;
        state = 1;
      } else {
        ans = ans * 2 % mod;
        i += 2;
        state = 2;
      }
    } else {
      if (s1[i] == s2[i]) {
        ans = ans * 1 % mod;
        i += 1;
        state = 1;
      } else {
        ans = ans * 3 % mod;
        i += 2;
        state = 2;
      }
    }
  }
  printf("%lld\n", ans);

  return 0;
}