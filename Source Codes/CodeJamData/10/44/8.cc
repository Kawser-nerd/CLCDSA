// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

#define EPSILON 1e-7
typedef complex<double> point;
vector<point> kozy;

template<class T> T cross_product(const complex<T> &A, const complex<T> &B) { return real(A) * imag(B) - real(B) * imag(A); }
template<class T> T size(const complex<T> &A) { return sqrt(real(A) * real(A) + imag(A) * imag(A)); }
// safe comparison with 0: is_zero, is_negative, is_positive, signum {{{
bool is_negative(int x) { return x<0; } bool is_zero(int x) { return x==0; } bool is_positive(int x) { return x>0; }
bool is_negative(long long x) { return x<0; } bool is_zero(long long x) { return x==0; } bool is_positive(long long x) { return x>0; }
bool is_negative(double x) { return x < -EPSILON; } bool is_zero(double x) { return abs(x) <= EPSILON; } bool is_positive(double x) { return x > EPSILON; }
bool is_negative(long double x) { return x < -EPSILON; } bool is_zero(long double x) { return abs(x) <= EPSILON; } bool is_positive(long double x) { return x > EPSILON; }
template<class T> int signum(const T &A) { if (is_zero(A)) return 0; if (is_negative(A)) return -1; return 1; }
// }}}
// safe equality test for points {{{ 
template<class T> bool are_equal(const complex<T> &A, const complex<T> &B) { return is_zero(real(B)-real(A)) && is_zero(imag(B)-imag(A)); }
// }}}

template<class T> vector< complex<T> > intersect_circle_circle(const complex<T> &C1, T r1, const complex<T> &C2, T r2) {
  vector< complex<T> > res;

  if (are_equal(C1,C2)) {
    // 2x the same point
    if (is_zero(r1) && is_zero(r2)) { res.push_back(C1); return res; } 
    // identical circles -- return 3 points
    if (is_zero(r1-r2)) { res.push_back(C1); res.push_back(C1); res.push_back(C1); return res; }
    // no intersection
    return res;
  }
    
  T d = size(C2-C1);
  // check for no intersection
  if (is_positive(d-r1-r2) || is_positive(r1-r2-d) || is_positive(r2-r1-d)) return res; 
  // check for a single intersection
  if (is_zero(d-r1-r2)) { res.push_back( (1.0/d) * ( r2*C1 + r1*C2 ) ); return res; }
  if (is_zero(r1-r2-d)) { res.push_back( C1 + (r1/d) * (C2-C1) ); return res; }
  if (is_zero(r2-r1-d)) { res.push_back( C2 + (r2/d) * (C1-C2) ); return res; }
  // general case: compute x and y offset of the intersections    
  T x = ( d*d - r2*r2 + r1*r1 ) / (2*d);
  T y = sqrt( 4*d*d*r1*r1 - ( d*d - r2*r2 + r1*r1 )*( d*d - r2*r2 + r1*r1 ) ) / (2*d);
  // I = (C1,C2) \cap chord, N = normal vector
  complex<T> I = (1.0/d) * ( (d-x)*C1 + x*C2 );
  complex<T> N( imag(C2-C1), -real(C2-C1) );
  T Nsize = size(N);
  N = N * (1/Nsize);
  // compute and return the points in lexicographic order
  complex<T> I1 = I + y*N;
  complex<T> I2 = I - y*N;
  if (is_positive(real(I1)-real(I2))) swap(I1,I2);
  if (is_zero(real(I1)-real(I2))) if (is_positive(imag(I1)-imag(I2))) swap(I1,I2);
  res.push_back(I1);
  res.push_back(I2);
  return res;
}

template<class T> T left_side_angle(const complex<T> &A, const complex<T> &B, const complex<T> &C) {
  double a1 = atan2( imag(A-B), real(A-B) );
  double a2 = atan2( imag(C-B), real(C-B) );
  double u = a1 - a2;
  if (u < 0) u += 2*M_PI;
  if (u >= 2*M_PI) u -= 2*M_PI;
  return u;
}

double slice(const point &S, double r, const point &A, const point &B) {
  double triangle = 0.5*abs(cross_product(A-S,B-S));
  double angle = left_side_angle(A,S,B);
  if (angle >= M_PI) angle = 2*M_PI - angle;
  double pizza = (angle / 2) * r * r;
  return pizza - triangle;
}

double bigslice(const point &S, double r, const point &A, const point &B) {
  double triangle = 0.5*abs(cross_product(A-S,B-S));
  double angle = left_side_angle(A,S,B);
  if (angle < M_PI) angle = 2*M_PI - angle;
  return triangle + (angle / 2) * r * r;
}

int main() {
  int T;
  cin >> T;
  FOR(t,1,T) {
    int N, M;
    cin >> N >> M;
    cout << "Case #" << t << ":";
    kozy.clear();
    REP(n,N) { double x,y; cin >> x >> y; kozy.push_back(point(x,y)); }
    REP(m,M) {
      double x,y; cin >> x >> y;
      point bucket(x,y);
      vector<double> radius;
      REP(n,N) radius.push_back( hypot( real(kozy[n])-real(bucket), imag(kozy[n])-imag(bucket) ) );
      double dist = hypot( real(kozy[0])-real(kozy[1]), imag(kozy[0])-imag(kozy[1]) );
      if (dist + radius[0] < radius[1] + EPSILON) {
        printf(" %.10f",M_PI*radius[0]*radius[0]);
        continue;
      }
      if (dist + radius[1] < radius[0] + EPSILON) {
        printf(" %.10f",M_PI*radius[1]*radius[1]);
        continue;
      }
      vector<point> I = intersect_circle_circle(kozy[0],radius[0],kozy[1],radius[1]);
      if (SIZE(I)<=1) {
        printf(" 0");
        continue;
      }
      if (radius[0] > radius[1]) {
        swap(kozy[0], kozy[1]);
        swap(radius[0], radius[1]);
      }
      double strana1 = cross_product( I[1]-I[0], kozy[0]-I[0] );
      double strana2 = cross_product( I[1]-I[0], kozy[1]-I[0] );
      if (strana1 * strana2 > EPSILON) {
        // na tej istej strane
        printf(" %.10f",bigslice(kozy[0],radius[0],I[0],I[1]) + slice(kozy[1],radius[1],I[0],I[1]) );
      } else {
        printf(" %.10f",slice(kozy[0],radius[0],I[0],I[1]) + slice(kozy[1],radius[1],I[0],I[1]) );
      }
    }
    cout << endl;
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
