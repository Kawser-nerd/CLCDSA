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
  scanf("%d", &n);
  vi p(n);
  rep (i, n) {
    scanf("%d", &p[i]);
    p[i] -= 1;
  }
  vector<bool> same(n, false);
  rep (i, n) {
    if (p[i] == i) {
      same[i] = true;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; ) {
    if (i == (n-1)) {
      if (same[i]) {
        cnt += 1;
      }
      break;
    }
    if (same[i]) {
      cnt += 1;
      if (same[i+1]) {
        i += 2;
      } else {
        i += 1;
      }
      continue;
    }
    i += 1;
  }
  printf("%d\n", cnt);

  return 0;
}