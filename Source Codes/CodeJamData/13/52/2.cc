#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator-(const Point& p) const {return Point(x - p.x, y - p.y);}
  Point operator+(const Point& p) const {return Point(x + p.x, y + p.y);}
  Point operator*(const double& c) const {return Point(x * c, y * c);}
  Point operator/(const double& c) const {return Point(x / c, y / c);}
  bool operator<(const Point& p) const {return x == p.x ? y < p.y : x < p.x;}
  bool operator==(const Point& p) const {return x == p.x && y == p.y;}
};

double dotp(const Point& a, const Point& b) {return a.x*b.x + a.y*b.y;}
double crossp(const Point& a, const Point& b) {return a.x*b.y - a.y*b.x;}

// Includes endpoints.  Returns (1000000000,1000000000) if no intersection.
Point intersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
  double cp1 = crossp(a2-a1, b1-a1);
  double cp2 = crossp(a2-a1, b2-a1);
  if (cp1 == 0 && cp2 == 0) {
    double dp1 = dotp(a2-a1, b1-a1);
    double dp2 = dotp(a2-a1, b2-a1);
    if (dp1 < 0 && dp2 < 0) return Point(1000000000, 1000000000);
    if (dp1 <= 0 && dp2 <= 0) return a1;
    dp1 = dotp(a1-a2, b1-a2);
    dp2 = dotp(a1-a2, b2-a2);
    if (dp1 < 0 && dp2 < 0) return Point(1000000000, 1000000000);
    if (dp1 <= 0 && dp2 <= 0) return a2;
    return Point(1000000001, 1000000001);
  }
  if (cp1 < 0 && cp2 < 0 || cp1 > 0 && cp2 > 0)
    return Point(1000000000, 1000000000);
  cp1 = crossp(b2-b1, a1-b1);
  cp2 = crossp(b2-b1, a2-b1);
  if (cp1 < 0 && cp2 < 0 || cp1 > 0 && cp2 > 0)
    return Point(1000000000, 1000000000);
  return (a2-a1) * (cp1 / (cp1-cp2)) + a1;
}

Point P[1001];

main() {
  int T, N, prob=1;
  for (cin >> T; T--;) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> P[i].x >> P[i].y;
    vector<int> perm;
    for (int i = 0; i < N; i++) perm.push_back(i);
    vector<int> ret;
    double retarea = 0;
    do {
      bool valid = true;
      for (int i = 0; i < N && valid; i++) {
        if (intersection(P[perm[i]], P[perm[(i+1)%N]],
                         P[perm[(i+1)%N]], P[perm[(i+2)%N]]).x == 1000000001)
          valid = false;
        for (int j = i+2; j < N && valid; j++) {
          if (i == 0 && j == N-1) continue;
          if (intersection(P[perm[i]], P[perm[(i+1)%N]],
                           P[perm[j]], P[perm[(j+1)%N]]).x != 1000000000)
            valid = false;
        }
      }
      if (valid) {
        double curarea = 0;
        for (int i = 0; i < N; i++)
          curarea += P[perm[i]].x * P[perm[(i+1)%N]].y -
                     P[perm[i]].y * P[perm[(i+1)%N]].x;
        if (curarea < 0) curarea = -curarea;
        if (curarea > retarea) {
          retarea = curarea;
          ret = perm;
        }
      }
    } while (next_permutation(perm.begin()+1, perm.end()));
    cout << "Case #" << prob++ << ":";
    for (int i = 0; i < ret.size(); i++) cout << ' ' << ret[i];
    cout << endl;
  }
}
