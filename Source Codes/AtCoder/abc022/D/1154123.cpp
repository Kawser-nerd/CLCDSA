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

#define INF 1000000010

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
struct LineSegment { Point p1, p2; };
typedef LineSegment Line;

enum e_ccw { COUNTER_CLOCKWISE, CLOCKWISE, ONLINE_BACK, ONLINE_FRONT, ON_LINE_SEGMENT };
auto ccw(Point p0, Point p1, Point p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  double outer_product = a.cross(b);
  double inner_product = a.dot(b);
  if (outer_product > EPS) { return COUNTER_CLOCKWISE; }
  if (outer_product < -EPS) { return CLOCKWISE; }
  if (inner_product < -EPS) { return ONLINE_BACK; }
  if (inner_product < b.norm()) { return ONLINE_FRONT; }
  return ON_LINE_SEGMENT;
}

vector<Point> convex_hull(vector<Point>& s) {
  if ((int)s.size() < 3) { return s; }
  int num = (int)s.size();
  vector<Point> ret(2 * num);

  int k = 0;
  for (int i = 0; i < num; ++i) {
    while (k >= 2 && ccw(ret[k-2], ret[k-1], s[i]) != COUNTER_CLOCKWISE) {
      k -= 1;
    }
    ret[k] = s[i];
    k += 1;
  }
  // now, ret[k-1] is filled
  int t = k+1;
  for (int i = num-2; i >= 0; --i) {
    while (k >= t && ccw(ret[k-2], ret[k-1], s[i]) != COUNTER_CLOCKWISE) {
      k -= 1;
    }
    ret[k] = s[i];
    k += 1;
  }
  ret.resize(k-1);
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<Point> a(n), b(n);
  {
    double x, y;
    rep (i, n) {
      scanf("%lf %lf", &x, &y);
      a[i] = Point(x, y);
    }
    rep (i, n) {
      scanf("%lf %lf", &x, &y);
      b[i] = Point(x, y);
    }
  }
  sort(all(a));
  sort(all(b));
  auto convex_a = convex_hull(a);
  auto convex_b = convex_hull(b);
  convex_a.push_back(convex_a[0]);
  convex_b.push_back(convex_b[0]);
  int m = (int)convex_a.size();
  double convex_length_a, convex_length_b;
  convex_length_a = convex_length_b = 0.;
  rep (i, m-1) {
    convex_length_a += (convex_a[i] - convex_a[i+1]).abs();
  }
  rep (i, m-1) {
    convex_length_b += (convex_b[i] - convex_b[i+1]).abs();
  }
  printf("%.9f\n", convex_length_b / convex_length_a);
  return 0;
}