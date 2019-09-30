#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 2*acos(0.0);

double pVal(double x, double y, double r) {
  if ((x*x + y*y) < (r*r))
    return x*y;
  double A = PI*r*r/4;
  if (x < r) {
    double a = acos(x/r);
    A -= (a*r*r - x*r*sin(a))/2;
    }
  if (y < r) {
    double a = acos(y/r);
    A -= (a*r*r - y*r*sin(a))/2;
    }
  return A;
  }

double sqVal(double x, double y, double s, double r) {
  double v = pVal(x+s, y+s, r);
  v += pVal(x-s, y-s, r);
  v -= pVal(x+s, y-s, r);
  v -= pVal(x-s, y+s, r);
  return v;
  }

double calc(double o, double d, double s, double r) {
  if (s <= 0) return 0;
  if (r <= 0) return 0;
  double a = 0;
  for (double x = o; x-s < r; x += d)
    for (double y = o; y-s < r; y += d)
      a += sqVal(x, y, s, r);
  return a;
  }

int main() {
  int N; cin >> N;
  cout << fixed << setprecision(6);
  for (int c = 1; c <= N; ++c) {
    double f, R, t, r, g;
    cin >> f >> R >> t >> r >> g;
    double holeArea = calc(r+g/2, 2*r+g, g/2-f, R-f-t);
    double wholeArea = PI*R*R/4;
    cout << "Case #" << c << ": " << 1-holeArea/wholeArea << "\n";
    }
  }