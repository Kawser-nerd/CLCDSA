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
  //using T = double;
  double x, y;

  Vector() : x(double(0)), y(double(0)) {}
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
struct LineSegment {
  Point p1, p2;
  LineSegment() {}
  LineSegment(Point p1_, Point p2_) : p1(p1_), p2(p2_) {}
};
typedef LineSegment Line;

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

bool intersect(Point p1, Point p2, Point p3, Point p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(LineSegment s1, LineSegment s2) {
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

int main() {
  Point chop1, chop2;
  scanf("%lf %lf %lf %lf", &chop1.x, &chop1.y, &chop2.x, &chop2.y);
  int n;
  scanf("%d", &n);
  vector<Point> vp(n);
  rep (i, n) {
    scanf("%lf %lf", &vp[i].x, &vp[i].y);
  }
  int cnt = 1;
  rep (i, n-1) {
    if (intersect(chop1, chop2, vp[i], vp[i+1])) {
      cnt += 1;
    }
  }

  printf("%d\n", cnt/2 + 1);

  return 0;
}