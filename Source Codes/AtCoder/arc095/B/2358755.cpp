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
  vi a(n);
  rep (i, n) {
    scanf("%d", &a[i]);
  }
  sort(all(a));
  int x = a.back();
  auto lb = lower_bound(all(a), x/2);
  int y = *lb;
  lb--;
  int z = *lb;

  double diffy = y - x/2.0;
  double diffz = x/2.0 - z;
  int ans;
  if (diffy < diffz) {
    ans = y;
  } else {
    ans = z;
  }
  printf("%d %d\n", x, ans);

  return 0;
}