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

ll NMAX = 1000000000;
ll num;

int main() {
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  num = h * w;
  ll l = 1;
  ll r = 1000000001;
  ll center;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    center = mid * (num-1) + 1;
    if (center <= NMAX) {
      l = mid;
    } else {
      r = mid;
    }
  }
  center = l * (num-1) + 1;
  ll sum = 0;
  int num_block = (H / h) * (W / w);
  sum -= num_block;
  sum += l * (H * W - num_block * h * w);
  if (sum > 0) {
    printf("Yes\n");
    rep (i, H) {
      rep (j, W) {
        printf("%lld ", ((i+1) % h == 0 && (j+1) % w == 0) ? -center : l);
      }
      printf("\n");
    }
  } else {
    printf("No\n");
  }
   
  return 0;
}