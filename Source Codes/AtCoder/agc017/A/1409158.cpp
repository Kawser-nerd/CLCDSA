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

ll po2(int x) {
  ll ret = 1;
  rep (i, x) {
    ret *= 2;
  }
  return ret;
}

int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  vi cnt(2, 0);
  rep (i, n) {
    int a;
    scanf("%d", &a);
    cnt[a % 2] += 1;
  }

  ll ans;
  if (cnt[1] == 0) {
    if (p == 1) {
      ans = 0;
    } else {
      ans = po2(n);
    }
  } else {
    ans = po2(n-1);
  }
  printf("%lld\n", ans);

  return 0;
}