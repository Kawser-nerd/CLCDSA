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

struct Point {
  int x, y;

  Point() {}
  Point(int x_, int y_) : x(x_), y(y_) {}
};

int main() {
  int x1, y1, x2, y2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  if (x1 > x2) {
    swap(x1, x2);
    swap(y1, y2);
  }
  int x_min, x_max, y_min, y_max;
  x_min = min(x1, x2);
  x_max = max(x1, x2);
  y_min = min(y1, y2);
  y_max = max(y1, y2);

  int n;
  scanf("%d", &n);

  vector<Point> xy;
  map<int, int> ytox;

  rep (i, n) {
    int x_, y_;
    scanf("%d %d", &x_, &y_);
    if (x_min <= x_ && x_ <= x_max && y_min <= y_ && y_ <= y_max) {
      xy.push_back(Point(x_, y_));
      ytox[y_] = x_;
    }
  }
  n = xy.size();

  if (n == 0) {
    printf("%.11f\n", 100.0 * (x_max - x_min + y_max - y_min));
    return 0;
  }
  double penalty = M_PI * 10 - 20;
  if (x_max == x_min || y_max == y_min) {
    printf("%.11f\n", (double)100.0 * (x_max - x_min + y_max - y_min) + n * penalty);
    return 0;
  }


  sort(all(xy), [](Point a, Point b) {
      return a.x < b.x;
      });

  if (y1 > y2) {
    reverse(all(xy));
  }

  vi l;
  l.push_back(xy[0].y);
  for (int i = 1; i < n; ++i) {
    if (l[(int)l.size() - 1] < xy[i].y) {
      l.push_back(xy[i].y);
    } else {
      *lower_bound(all(l), xy[i].y) = xy[i].y;
    }
  }
  int n_s = l.size();
  int n_p = 0;
  if (n_s == 1 + min(x_max - x_min, y_max - y_min)) {
    n_s -= 1;
    n_p = 1;
  }

  double shortcut = 20 - M_PI * 5;
  printf("%.11f\n", 100.0 * (x_max - x_min + y_max - y_min) - n_s * shortcut + n_p * penalty);

  return 0;
}