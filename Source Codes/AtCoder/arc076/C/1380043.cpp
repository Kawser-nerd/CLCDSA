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
#define debug(x) //cerr<< #x <<": "<<x<<endl
#define debug2(x,y) //cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<bool> db;
template<class T> using vv=vector<vector< T > >;

int r, c, n;
bool on_edge(int x, int y) {
  return (x == 0 || x == r) || (y == 0 || y == c);
}

double xcenter, ycenter;
double get_atan(vi &a) {
  return atan2(a[1] - ycenter, a[0] - xcenter);
}

int main() {
  scanf("%d %d %d", &r, &c, &n);
  xcenter = r / 2.0;
  ycenter = c / 2.0;
  vvi points;
  rep (i, n) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (on_edge(x1, y1) && on_edge(x2, y2)) {
      vi point1 = {x1, y1, i};
      vi point2 = {x2, y2, i};
      points.push_back(point1);
      points.push_back(point2);
    }
  }
  int m = points.size();
  sort(all(points), [](vi a, vi b) {
      return get_atan(a) < get_atan(b);
      });

  deque<int> stk;
  rep (i, m) {
    int num = points[i][2];
    if (stk.empty()) {
      stk.push_back(num);
      continue;
    }
    if (stk.back() == num) {
      stk.pop_back();
    } else {
      stk.push_back(num);
    }
  }
  if (stk.empty()) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}