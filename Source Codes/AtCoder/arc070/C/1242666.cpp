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
  vll l(n), r(n), width(n), mid(n);
  rep (i, n) {
    scanf("%lld%lld", &l[i], &r[i]);
    l[i] *= 2;
    r[i] *= 2;
    width[i] = r[i] - l[i];
    mid[i] = (r[i] + l[i]) / 2;
  }
  ll left_offset, right_offset;
  left_offset = right_offset = 0;
  ll minval = 0;
  priority_queue<ll, vll, less<ll> > left;
  priority_queue<ll, vll, greater<ll> > right;

  left.push(mid[0]);
  right.push(mid[0]);

  FOR (i, 1, n) {
    ll width_ = (width[i] + width[i-1]) / 2;
    left_offset -= width_;
    right_offset += width_;
    ll max_left = left.top();
    ll min_right = right.top();

    assert(max_left + left_offset <= min_right + right_offset);

    if (max_left + left_offset <= mid[i] && mid[i] <= min_right + right_offset) {
      left.push(mid[i] - left_offset);
      right.push(mid[i] - right_offset);
    } else {
      if (mid[i] < max_left + left_offset) {
        minval += max_left + left_offset - mid[i];

        right.push(max_left + left_offset - right_offset);
        left.pop();
        left.push(mid[i] - left_offset);
        left.push(mid[i] - left_offset);
      } else {
        minval += mid[i] - (min_right + right_offset);

        left.push(min_right + right_offset - left_offset);
        right.pop();
        right.push(mid[i] - right_offset);
        right.push(mid[i] - right_offset);
      }
    }
  }

  printf("%lld\n", minval / 2);

  return 0;
}