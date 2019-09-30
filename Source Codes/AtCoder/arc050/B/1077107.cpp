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

ll r, b, x, y;
ll r_, b_;

bool is_possible(ll mid) {
  r_ = r;
  b_ = b;
  r_ -= mid;
  b_ -= mid;
  if (r_ < 0 || b_ < 0) {
    return false;
  }
  if (r_ / (x - 1) + b_ / (y - 1) >= mid) {
    return true;
  }
  return false;
}

int main() {
  scanf("%lld %lld", &r, &b);
  scanf("%lld %lld", &x, &y);

  ll low = 0;
  ll high = 1e18;
  ll mid;
  while (low + 1 < high) {
    mid = (low + high) / 2;
    if (is_possible(mid)) {
      low = mid;
    } else {
      high = mid;
    }
  }
  printf("%lld\n", low);

  return 0;
}