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

// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size(); s << "\n";
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  s << "\n"; return s;
}

// cout 2-dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) { s << vv[i]; }
  return s;
}

// cout deque
template<typename T> ostream& operator<<(ostream& s, const deque<T>& v) {
  int len = v.size(); s << "\n";
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  s << "\n"; return s;
}

// cout 2-dimentional deque
template<typename T> ostream& operator<<(ostream& s, const deque< deque<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) { s << vv[i]; }
  return s;
}

int r, c, n;
bool on_edge(int x, int y) {
  return (x == 0 || x == r) || (y == 0 || y == c);
}

double xcenter, ycenter;
double get_atan(vi a) {
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

  debug(points);

  deque<int> stk;
  set<int> si;
  rep (i, m) {
    int num = points[i][2];
    if (si.find(num) == end(si)) {
      si.insert(num);
      stk.push_back(num);
    } else if (stk.back() == num) {
      stk.pop_back();
    } else {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");

  return 0;
}