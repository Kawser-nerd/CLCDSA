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

#define EPS (1e-10)
struct Vector {
  double x, y;

  Vector() : x(0), y(0) {}
  Vector(double x_, double y_) : x(x_), y(y_) {}

  Vector operator + (Vector& v) { return Vector(x + v.x, y + v.y); }
  Vector operator - (Vector& v) { return Vector(x - v.x, y - v.y); }
  Vector operator * (double& k) { return Vector(x * k, y * k); }
  Vector operator / (double& k) { return Vector(x / k, y / k); }

  double norm() { return x * x + y * y; }
  double abs() { return sqrt(norm()); }

  bool operator < (const Vector& v) const {
    return x != v.x ? x < v.x : y < v.y;
  }
  bool operator == (const Vector& v) const {
    return fabs(x - v.x) < EPS && fabs(y - v.y) < EPS;
  }

  double dot(const Vector& v) { return x * v.x + y * v.y; }
  double cross(const Vector& v) { return x * v.y - y * v.x; }
};

typedef Vector Point;

//enum e_ccw { COUNTER_CLOCKWISE, CLOCKWISE, ONLINE_BACK, ONLINE_FRONT, ON_LINE_SEGMENT };
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_LINE_SEGMENT = 0;
auto ccw(Point p0, Point p1, Point p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  double outer_product = a.cross(b);
  double inner_product = a.dot(b);
  if (outer_product > EPS) { return COUNTER_CLOCKWISE; }
  if (outer_product < -EPS) { return CLOCKWISE; }
  if (inner_product < -EPS) { return ONLINE_BACK; }
  if (a.norm() < b.norm()) { return ONLINE_FRONT; }
  return ON_LINE_SEGMENT;
}

struct LineSegment { Point p1, p2; };
typedef LineSegment Line;

bool intersect(Point p1, Point p2, Point p3, Point p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersect(LineSegment s1, LineSegment s2) {
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

void print_ans(vector<Point>& d) {
  double ans = 0.;
  int m = (int)d.size();
  rep (i, m-1) {
    ans += (d[i] - d[i+1]).abs();
  }
  printf("%.9f\n", ans);
  exit(0);
}

typedef vector<double> vd;
int main() {
  int n;
  scanf("%d", &n);
  Point start, goal;
  start.y = 0;
  goal.y = n;
  scanf("%lf %lf", &start.x, &goal.x);
  vector<Point> left(n+1), right(n+1);
  rep (i, n+1) {
    int l, r;
    scanf("%d %d", &l, &r);
    left[i] = Point(l, i);
    right[i] = Point(r, i);
  }

  vector<Point> determined;
  determined.reserve(n);
  deque<Point> cl(n+1), cr(n+1);
  cl[0] = cr[0] = start;
  int kl, kr;
  kl = kr = 1;
  FOR (y, 1, n+1) {
    while (kl >= 2 && ccw(cl[kl-2], cl[kl-1], left[y]) != COUNTER_CLOCKWISE) {
      kl -= 1;
    }
    cl[kl] = left[y];
    kl += 1;
    while (kr >= 2 && ccw(cr[kr-2], cr[kr-1], right[y]) != CLOCKWISE) {
      kr -= 1;
    }
    cr[kr] = right[y];
    kr += 1;
    // update completed
    assert (cl[0] == cr[0]);
    if (ccw(cr[0], cr[1], cl[1]) == COUNTER_CLOCKWISE) {
      continue;
    }
    assert (kl == 2 || kr == 2);
    auto& crossing = (kl == 2) ? cl : cr;
    auto& crossed = (kl == 2) ? cr : cl;
    auto& ind = (kl == 2) ? kr : kl;
    int cw = (kl == 2) ? COUNTER_CLOCKWISE : CLOCKWISE;
    while ((int)crossed.size() >= 2) {
      if (ccw(crossed[0], crossed[1], crossing[1]) == cw) {
        crossing[0] = crossed[0];
        break;
      } else {
        determined.push_back(crossed[0]);
        crossed.pop_front();
        ind -= 1;
      }
    }
  }

  deque<Point> crossing = {cl[0], goal};
  int ccw_l = ccw(crossing[0], crossing[1], cl[1]);
  int ccw_r = ccw(crossing[0], crossing[1], cr[1]);
  if ((ccw_l == COUNTER_CLOCKWISE || ccw_l == ON_LINE_SEGMENT) && (ccw_r == CLOCKWISE || ccw_r == ON_LINE_SEGMENT)) {
    determined.push_back(crossing[0]);
    determined.push_back(crossing[1]);
    print_ans(determined);
    return 0;
  }
  bool flag = (ccw_l == CLOCKWISE);
  auto& crossed = flag ? cl : cr;
  auto& ind = flag ? kl : kr;
  int cw = flag ? CLOCKWISE : COUNTER_CLOCKWISE;

  while ((int)crossed.size() >= 2) {
    if (ccw(crossed[0], crossed[1], crossing[1]) == cw) {
      crossing[0] = crossed[0];
      determined.push_back(crossed[0]);
      determined.push_back(crossing[1]);
      print_ans(determined);
      return 0;
    } else {
      determined.push_back(crossed[0]);
      crossed.pop_front();
      ind -= 1;
    }
  }
  determined.push_back(crossing[1]);
  print_ans(determined);

  return 0;
}