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

int n;

int calc(vi lis) {
  int ret = 0;
  int l = lis.size();
  if (lis.empty()) {
    return n;
  }
  ret = max(ret, lis[0]);
  rep (i, l-1) {
    ret = max(ret, lis[i+1] - lis[i] - 1);
  }
  ret = max(ret, n-1 - lis[l-1]);
  return ret;
}

int main() {
  string s;
  cin >> s;
  n = s.length();
  vector<bool> checked(26, false);
  int ans = 1000;
  rep (i, n) {
    char c = s[i];
    if (checked[s[i] - 'a']) {
      continue;
    }
    checked[s[i] - 'a'] = true;
    vi lis = {i};
    FOR (j, i+1, n) {
      if (s[j] == c) {
        lis.push_back(j);
      }
    }
    ans = min(ans, calc(lis));
  }
  printf("%d\n", ans);
  return 0;
}