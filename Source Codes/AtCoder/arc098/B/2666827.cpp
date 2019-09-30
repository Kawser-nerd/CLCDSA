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


vi last_used;

void update_add(int x, int ind) {
  rep (i, 20) {
    if (((x >> i) & 1) == 1) {
      last_used[i] = ind;
    }
  }
}

void update_remove(int ind) {
  rep (i, 20) {
    if (last_used[i] < ind) {
      last_used[i] = -1;
    }
  }
}

int last_used_index(int x) {
  int ret = -1;
  rep (i, 20) {
    if (((x >> i) & 1) == 1) {
      ret = max(ret, last_used[i]);
    }
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  vi a(n);
  rep (i, n) {
    scanf("%d", &a[i]);
  }
  last_used.assign(20, -1);
  int start = 0;
  update_add(a[0], 0);
  ll cnt = 1;
  FOR (finish, 1, n) {
    int lui = last_used_index(a[finish]);
    if (lui >= 0) {
      start = lui + 1;
      update_remove(start);
    }
    cnt += (finish - start + 1);
    update_add(a[finish], finish);
  }
  printf("%lld\n", cnt);
    
  return 0;
}