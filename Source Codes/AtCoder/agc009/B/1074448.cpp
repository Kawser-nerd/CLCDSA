#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
template<class T> using vv=vector<vector< T > >;

vector<vector<int> > b;

int get_depth(int x) {
  int sz = (int)b[x].size();
  if (sz == 0) {
    return 0;
  }

  vector<int> ret(sz);
  rep (i, sz) {
    ret[i] = get_depth(b[x][i]);
  }
  sort(all(ret), std::greater<int>());
  rep (i, sz) {
    ret[i] += (i+1);
  }
  sort(all(ret), std::greater<int>());
  return ret[0];
}

int main() {
  int n;
  scanf("%d", &n);
  vi a(n+1, 0);
  b.resize(n+1);
  FOR (i, 2, n+1) {
    scanf("%d", &a[i]);
    b[a[i]].push_back(i);
  }

  int ans = get_depth(1);
  printf("%d\n", ans);
  return 0;
}