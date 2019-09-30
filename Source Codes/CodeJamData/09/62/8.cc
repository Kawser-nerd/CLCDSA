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
// BEGIN CUT HERE
#define DEBUG(var) { cout << #var << ": " << (var) << endl; }
template <class T> ostream& operator << (ostream &os, const vector<T> &temp) { os << "[ "; for (unsigned int i=0; i<temp.size(); ++i) os << (i?", ":"") << temp[i]; os << " ]"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const set<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const multiset<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const pair<S,T> &a) { os << "(" << a.first << "," << a.second << ")"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const map<S,T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (it->first) << "->" << it->second; os << " }"; return os; } // DEBUG
// END CUT HERE
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

// The whole geometry library {{{
/* Surely won't compile with COORD_TYPE integer:
 * size, normalize, left_side_angle
 *
 * (If compiles), won't work properly with COORD_TYPE integer:
 * poly_area, center_of_mass, intersect_*, rotate, distance_*, circumcircle_center
 */

#define COORD_TYPE double // data type used to store the coordinates: %d || %lld || %lf || %Lf
typedef complex<COORD_TYPE> point;
typedef vector<point> poly; // if used to store a polygon, don't repeat the first vertex 

#define EPSILON (1e-7) // epsilon used for computations involving doubles ; dec to 1e-9 for %Lf 

#ifndef M_PI // UVa judge doesn't know M_PI
#define M_PI 3.14159265358979323846 
#endif 

// safe comparison function according to [argument,size]: compare_arg {{{
template<class T> bool compare_arg(const complex<T> &A, const complex<T> &B) { 
  // [0,0] ide uplne na zaciatok
  if (are_equal(B,point(0,0))) return 0;
  if (are_equal(A,point(0,0))) return 1;
  // chceme poradie: pod osou x zlava doprava, kladna poloos, nad osou sprava dolava, zaporna poloos
  int sgnA = signum(imag(A));
  int sgnB = signum(imag(B));
  if (sgnA == 0) if (signum(real(A))<0) sgnA = 2;
  if (sgnB == 0) if (signum(real(B))<0) sgnB = 2;
  if (sgnA != sgnB) return (sgnA < sgnB);
  // v ramci polroviny sortime podla clockwise
  if (counterclockwise(A,B)) return 1;
  if (clockwise(A,B)) return 0;
  // a ak sa este nerozhodlo, podla vzdialenosti, blizsie skor
  return (square_size(A) < square_size(B));
}
// }}}
// safe comparison functions acc. to [x,y] and [y,x]: compare_XY, compare_YX {{{
template<class T> bool compare_XY(const complex<T> &A, const complex<T> &B) { if (!is_zero(real(A)-real(B))) return (is_negative(real(A)-real(B))); return (is_negative(imag(A)-imag(B))); }
template<class T> bool compare_YX(const complex<T> &A, const complex<T> &B) { if (!is_zero(imag(A)-imag(B))) return (is_negative(imag(A)-imag(B))); return (is_negative(real(A)-real(B))); }
// }}}
#ifdef LESS_THAN_COMPARES_LEXICOGRAPHICALLY
// bool operator < such that   (a+bi) < (c+di)  <==> [a,b] < [c,d] {{{
template<class T> bool operator < (const complex<T> &A, const complex<T> &B) { if (real(A) != real(B)) return (real(A) < real(B)); return (imag(A) < imag(B)); }

template<class T> bool operator < (const T &A, const complex<T> &B) { return complex<T>(A) < B; }
template<class T> bool operator < (const complex<T> &A, const T &B) { return A < complex<T>(B); }

template<class T> bool operator > (const complex<T> &A, const complex<T> &B) { return B < A; }
template<class T> bool operator > (const T &A, const complex<T> &B) { return B < A; }
template<class T> bool operator > (const complex<T> &A, const T &B) { return B < A; } 
// }}}
#endif

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
// cross-product, dot_product, square_size (=dot_product(A,A)) for 2D vectors {{{
template<class T> T square_size(const complex<T> &A) { return real(A) * real(A) + imag(A) * imag(A); }
template<class T> T dot_product(const complex<T> &A, const complex<T> &B) { return real(A)*real(B) + imag(A)*imag(B); }
template<class T> T cross_product(const complex<T> &A, const complex<T> &B) { return real(A) * imag(B) - real(B) * imag(A); }
// }}}
// size, normalize for 2D real vectors {{{
template<class T> T size(const complex<T> &A) { return sqrt(real(A) * real(A) + imag(A) * imag(A)); }
template<class T> void normalize(complex<T> &A) { T Asize = size(A); A *= (1/Asize); }
// }}}
// safe colinearity and orientation tests: colinear, clockwise, counterclockwise {{{
template<class T> bool colinear(const complex<T> &A, const complex<T> &B, const complex<T> &C) { return is_zero( cross_product( B-A, C-A )); }
template<class T> bool colinear(const complex<T> &B, const complex<T> &C) { return is_zero( cross_product( B, C )); }

template<class T> bool clockwise(const complex<T> &A, const complex<T> &B, const complex<T> &C) { return is_negative( cross_product( B-A, C-A )); }
template<class T> bool clockwise(const complex<T> &B, const complex<T> &C) { return is_negative( cross_product( B, C )); }

template<class T> bool counterclockwise(const complex<T> &A, const complex<T> &B, const complex<T> &C) { return is_positive( cross_product( B-A, C-A )); }
template<class T> bool counterclockwise(const complex<T> &B, const complex<T> &C) { return is_positive( cross_product( B, C )); }
// }}}

// polygon area: twice_signed_poly_area, poly_area {{{
template<class T> T twice_signed_poly_area(const vector< complex<T> > &V) { T res = 0; for (unsigned int i=0; i<V.size(); i++) res += cross_product( V[i], V[(i+1)%V.size()] ); return res; }
template<class T> T poly_area(const vector< complex<T> > &V) { return abs(0.5 * twice_signed_poly_area(V)); }
// }}}
// compute the center of mass of a polygon: center_of_mass {{{
template<class T> complex<T> center_of_mass(const vector< complex<T> > &V ) {
  complex<T> sum(0,0);
  T twice_area = 0.0;
  for (unsigned i=0; i<V.size(); i++) {
    sum += cross_product( V[i], V[(i+1)%V.size()] ) * ( V[i] + V[(i+1)%V.size()] );
    twice_area += cross_product( V[i], V[(i+1)%V.size()] );
  }
  sum *= 1.0 / (3.0 * twice_area);
  return sum;
}
// }}}
// compute a CCW convex hull with no unnecessary points: convex_hull {{{
template<class T> vector< complex<T> > convex_hull( vector< complex<T> > V ) { 
  // handle boundary cases
  if (V.size() == 2) if (are_equal(V[0],V[1])) V.pop_back();
  if (V.size() <= 2) return V;
  // find the bottommost point -- this can be optimized!
  sort(V.begin(), V.end(), compare_YX<COORD_TYPE> );

  complex<T> offset = V[0];
  for (unsigned int i=0; i<V.size(); i++) V[i] -= offset;
  sort(V.begin()+1, V.end(), compare_arg<COORD_TYPE> );

  int count = 2;
  vector<int> hull(V.size()+2);
  for (unsigned int i=0; i<2; i++) hull[i]=i;
 
  for (unsigned int i=2; i<V.size(); i++) {
    while (count>=2 && !counterclockwise( V[hull[count-2]], V[hull[count-1]], V[i] ) ) count--;
    hull[count++]=i;
  }
  
  vector< complex<T> > res;
  for (int i=0; i<count; i++) res.push_back( V[hull[i]] + offset );

  if (res.size()==2) if (are_equal(res[0],res[1])) res.pop_back();
  return res;
}

// }}}

// safe test whether a point C \in [A,B], C \in (A,B): is_on_segment, is_inside_segment {{{
template<class T> bool is_on_segment(const complex<T> &A, const complex<T> &B, const complex<T> &C) { 
  if (!colinear(A,B,C)) return 0; 
  return ! is_positive( dot_product(A-C,B-C) ); 
}
template<class T> bool is_inside_segment(const complex<T> &A, const complex<T> &B, const complex<T> &C) { 
  if (!colinear(A,B,C)) return 0; 
  return is_negative( dot_product(A-C,B-C) ); 
}
// }}}
// winding number of a poly around a point (not on its boundary): winding_number(pt,poly) {{{
template<class T> int winding_number( const complex<T> &bod, const vector< complex<T> > &V ) {
  int wn = 0;
  for (unsigned int i=0; i<V.size(); i++) {
    if (! is_positive( imag(V[i]) - imag(bod) )) {
      if (is_positive( imag(V[(i+1)%V.size()]) - imag(bod) ))
        if (counterclockwise( V[i], V[(i+1)%V.size()], bod ))
          ++wn;
    } else {
      if (! is_positive( imag(V[(i+1)%V.size()]) - imag(bod) ))
        if (clockwise( V[i], V[(i+1)%V.size()], bod ))
          --wn;
    }
  }
  return wn;
}
// }}}

// test whether a point is inside a polygon: is_inside {{{
template<class T> int is_inside( const complex<T> &bod, const vector< complex<T> > &V ) { 
  for (unsigned int i=0; i<V.size(); i++) if (is_on_segment(V[i],V[(i+1)%V.size()],bod)) return true;
  return winding_number(bod,V) != 0; 
}
// }}}

// test whether a polygon is convex: is_poly_convex {{{
template<class T> bool is_poly_convex(const vector< complex<T> > &V) {
  int cw=0, ccw=0;
  unsigned int N = V.size();
  for (unsigned i=0; i<V.size(); i++) if (clockwise(V[i],V[(i+1)%N],V[(i+2)%N])) { cw=1; break; }
  for (unsigned i=0; i<V.size(); i++) if (counterclockwise(V[i],V[(i+1)%N],V[(i+2)%N])) { ccw=1; break; }
  return (! (cw && ccw));
}
// }}}
// test whether a polygon is given in clockwise order: is_poly_clockwise {{{
template<class T> bool is_poly_clockwise(const vector< complex<T> > &V) { 
  return is_negative(twice_signed_poly_area(V));
}
// }}}

// intersect lines (A,B) and (C,D), return 2 pts if identical: intersect_line_line {{{
template<class T> vector< complex<T> > intersect_line_line(const complex<T> &A, const complex<T> &B, const complex<T> &C, const complex<T> &D) {
  vector< complex<T> > res;
  
  complex<T> U = B-A, V = D-C;
  if (colinear(U,V)) { // identical or parallel
    if (colinear(U,C-A)) { res.push_back(A); res.push_back(B); }
    return res;
  }
  // one intersection point
  T k = ( cross_product(C,V) - cross_product(A,V) ) / cross_product(U,V);
  res.push_back(A + k*U);
  return res;
}
// }}}
// intersect segments [A,B] and [C,D], may return endpoints of a segment: intersect_segment_segment {{{
template<class T> vector< complex<T> > intersect_segment_segment(const complex<T> &A, const complex<T> &B, const complex<T> &C, const complex<T> &D) {
  vector< complex<T> > res;

  complex<T> U = B-A, V = D-C, W = C-A, X = D-A;
  if (colinear(U,V)) { // parallel
    // check for degenerate cases
    if (are_equal(A,B)) { if (is_on_segment(C,D,A)) res.push_back(A); return res; }
    if (are_equal(C,D)) { if (is_on_segment(A,B,C)) res.push_back(C); return res; }
    // two parallel segments
    if (!colinear(U,W)) return res; // not on the same line
    
    T ssU = square_size(U), ssW = square_size(W), ssX = square_size(X);

    // does A coincide with C or D? 
    
    if (is_zero(ssW)) {
      res.push_back(A);
      if (is_negative(dot_product(U,X))) return res; // B, D on different sides 
      if (is_negative(ssU-ssX)) res.push_back(B); else res.push_back(D); 
      return res;
    }
    if (is_zero(ssX)) {
      res.push_back(A);
      if (is_negative(dot_product(U,W))) return res; // B, C on different sides
      if (is_negative(ssU-ssW)) res.push_back(B); else res.push_back(C); 
      return res;
    }
    
    if (is_inside_segment(C,D,A)) {
      // A is inside CD, intersection is [A,?] 
      res.push_back(A);
      if (is_positive(dot_product(U,W))) { // B,C on the same side 
        if (is_negative(ssU-ssW)) res.push_back(B); else res.push_back(C); 
        return res;
      } else { // B,D on the same side 
        if (is_negative(ssU-ssX)) res.push_back(B); else res.push_back(D); 
        return res;
      }
    } else {
      // segment CD is strictly on one side of A
      if (ssW < ssX) {
        // A_C_D
        if (is_negative(dot_product(U,W))) return res; // B is on the other side
        if (is_negative(ssU-ssW)) return res; // B before C
        if (are_equal(B,C)) { res.push_back(B); return res; }
        res.push_back(C);
        if (is_negative(ssU-ssX)) res.push_back(B); else res.push_back(D); 
        return res;
      } else {
        // A_D_C
        if (is_negative(dot_product(U,X))) return res; // B is on the other side 
        if (is_negative(ssU-ssX)) return res; // B before D
        if (are_equal(B,D)) { res.push_back(B); return res; }
        res.push_back(D);
        if (is_negative(ssU-ssW)) res.push_back(B); else res.push_back(C); 
        return res;
      }
    }
  }    
  // not parallel, at most one intersection point
  T k = ( cross_product(C,V) - cross_product(A,V) ) / cross_product(U,V);
  complex<T> cand = A + k*U;
  if (is_on_segment(A,B,cand) && is_on_segment(C,D,cand)) res.push_back(cand);
  return res;
}
// }}}
// intersect a poly and a halfplane to the left of [A,B): intersect_poly_halfplane {{{
template<class T> vector< complex<T> > intersect_poly_halfplane(const vector< complex<T> > &V, const complex<T> &A, const complex<T> &B) { 
  int N = V.size();
  vector< complex<T> > res;

  if (N == 0) return res;
  if (N == 1) { if (! clockwise(A,B,V[0]) ) return V; else return res; }

  for (int i=0; i<N; i++) {
    if (! clockwise(A,B,V[i])) res.push_back(V[i]);
    int intersects = 0;
    if (counterclockwise(A,B,V[i])) if (clockwise(A,B, V[(i+1)%N] )) intersects = 1;
    if (clockwise(A,B,V[i])) if (counterclockwise(A,B, V[(i+1)%N] )) intersects = 1;
    if (intersects) {
      poly tmp = intersect_line_line(A,B,V[i], V[(i+1)%N] );
      res.push_back( tmp[0] ); // vieme, ze ma len jeden bod
    }
  }
  return res;
}
// }}}
// intersect two convex polygons, result is CCW: intersect_cpoly_cpoly {{{
template<class T> vector< complex<T> > intersect_cpoly_cpoly(vector< complex<T> > V1, vector< complex<T> > V2) { 
  if (is_poly_clockwise(V1)) reverse(V1.begin(),V1.end());
  if (is_poly_clockwise(V2)) reverse(V2.begin(),V2.end());
  for (unsigned int i=0; i<V2.size(); i++) V1 = intersect_poly_halfplane(V1,V2[i],V2[(i+1) % V2.size() ]);
  return V1;
}
// }}}
// intersect circles (C1,r1) and (C2,r2), 3 pts returned if \equiv: intersect_circle_circle {{{
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
    
  T d = sqrt(square_size(C2-C1));
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
  T Nsize = sqrt(square_size(N));
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
// }}}

// compute distance: point A, line (B,C): distance_point_line {{{
template<class T> T distance_point_line(const complex<T> &A, const complex<T> &B, const complex<T> &C) {
  complex<T> N ( -imag(B-C), real(B-C) );
  normalize(N);
  T tmp = dot_product(N,B-A);
  return abs(tmp);
}
// }}}
// compute distance: point A, segment [B,C]: distance_point_segment {{{
template<class T> T distance_point_segment(const complex<T> &A, const complex<T> &B, const complex<T> &C) {
  T res = min( size(B-A), size(C-A) );
  
  complex<T> N ( -imag(B-C), real(B-C) );
  normalize(N);
  T tmp = dot_product(N,B-A);
  complex<T> paeta = A + tmp*N;
  if (is_on_segment(B,C,paeta)) res = min(res,abs(tmp));
  return res; 
}
// }}}
// compute distance: line (A,B), line (C,D): distance_line_line {{{
template<class T> T distance_line_line(const complex<T> &A, const complex<T> &B, const complex<T> &C, const complex<T> &D) {
  if (!colinear(B-A,D-C)) return 0.0;
  return distance_point_line(A,C,D);
}
// }}}
// compute distance: segment [A,B], line (C,D): distance_segment_line {{{
template<class T> T distance_segment_line(const complex<T> &A, const complex<T> &B, const complex<T> &C, const complex<T> &D) {
  if (! is_positive( cross_product(D-C,A-C) * cross_product(D-C,B-C) )) return 0; // they intersect
  return min( distance_point_line(A,C,D), distance_point_line(B,C,D) );
}
// }}}
// compute distance: segment [A,B], segment [C,D]: distance_segment_segment {{{
template<class T> T distance_segment_segment(const complex<T> &A, const complex<T> &B, const complex<T> &C, const complex<T> &D) {
  vector< complex<T> > isect = intersect_segment_segment(A,B,C,D);
  if (isect.size()) return 0; // they intersect
  
  T res =  distance_point_segment(A,C,D);
  res = min(res, distance_point_segment(B,C,D));
  res = min(res, distance_point_segment(C,A,B));
  res = min(res, distance_point_segment(D,A,B));
  return res; 
}
// }}}

// circumcircle center for three points A,B,C (even colinear): {{{
template<class T> complex<T> circumcircle_center(const complex<T> &A, const complex<T> &B, const complex<T> &C) {
  T a = 0, bx = 0, by = 0;
  a += real(A) * imag(B) + real(B) * imag(C) + real(C) * imag(A);
  a -= real(B) * imag(A) + real(C) * imag(B) + real(A) * imag(C);
  if (is_zero(a)) { if (is_on_segment(A,B,C)) return 0.5*(A+B); if (is_on_segment(A,C,B)) return 0.5*(A+C); return 0.5*(B+C); }
  bx += square_size(A) * imag(B) + square_size(B) * imag(C) + square_size(C) * imag(A);
  bx -= square_size(B) * imag(A) + square_size(C) * imag(B) + square_size(A) * imag(C);
  by -= square_size(A) * real(B) + square_size(B) * real(C) + square_size(C) * real(A);
  by += square_size(B) * real(A) + square_size(C) * real(B) + square_size(A) * real(C);
  return complex<T> ( bx / (2*a) , by / (2*a) );
}
// }}}

// rotate(point,center,CCW angle): {{{
template<class T> complex<T> rotate_point(const complex<T> &bod, const complex<T> &stred, T uhol) { 
  complex<T> mul(cos(uhol),sin(uhol)); return ((bod-stred)*mul)+stred; 
}
// }}}
// rotate(poly,center,CCW angle): {{{
template<class T> vector< complex<T> > rotate_poly(vector< complex<T> > V, const complex<T> &stred, T uhol) { 
  for (unsigned int i=0; i<V.size(); i++) V[i] = rotate_point(V[i],stred,uhol); return V; 
}
// }}}

// angle on the left side of B in polyline A->B->C: left_side_angle {{{
template<class T> T left_side_angle(const complex<T> &A, const complex<T> &B, const complex<T> &C) {
  double a1 = atan2( imag(A-B), real(A-B) );
  double a2 = atan2( imag(C-B), real(C-B) );
  double u = a1 - a2;
  if (u < 0) u += 2*M_PI;
  if (u >= 2*M_PI) u -= 2*M_PI;
  return u;
}
// }}}
// }}}

#include <tr1/unordered_map>

int main() {
  int T;
  scanf("%d",&T);
  FOR(t,1,T) {
    poly P;
    int N;
    scanf("%d",&N);
    REP(n,N) {
      double x,y;
      scanf("%lf%lf",&x,&y);
      P.push_back(point(x,y));
    }
    double result = 1e30;
    REP(i,10000) {
      int a = rand() % N;
      int b = rand() % N;
      int c = rand() % N;
      if (a==b) continue;
      if (a==c) continue;
      if (c==b) continue;
      double toto = size(P[a]-P[b]) + size(P[b]-P[c]) + size(P[c]-P[a]);
      result = min(result,toto);
    }
    // std::tr1::unordered_map< pair<int,int>, vector<int> > buckets;
    map< pair<int,int>, vector<int> > buckets;
    double blen = result + 0.1;

    REP(i,N) {
      int bx = int( real(P[i])/blen );
      int by = int( imag(P[i])/blen );
      buckets[ make_pair(bx,by) ].push_back(i);
    }
    FOREACH(it,buckets) {
      int bx = it->first.first;
      int by = it->first.second;
      vector<int> cand;
      for (int dx=0; dx<=0; ++dx)
      for (int dy=0; dy<=0; ++dy) {
        pair<int,int> p(bx+dx,by+dy);
        if (!buckets.count(p)) continue;
        REP(i,SIZE(buckets[p])) cand.push_back( buckets[p][i] );
      }
      REP(i,SIZE(cand)) REP(j,i) REP(n,j) {
        double toto = size(P[cand[n]]-P[cand[i]]) + size(P[cand[i]]-P[cand[j]]) + size(P[cand[j]]-P[cand[n]]);
        result = min(result,toto);
      }
    }

    blen = result + 0.1;
    buckets.clear();

    REP(i,N) {
      int bx = int( real(P[i])/blen );
      int by = int( imag(P[i])/blen );
      buckets[ make_pair(bx,by) ].push_back(i);
    }
    FOREACH(it,buckets) {
      int bx = it->first.first;
      int by = it->first.second;
      vector<int> cand = it->second;
      for (int dx=-1; dx<=1; ++dx)
      for (int dy=-1; dy<=1; ++dy) {
        if (dx==0 && dy==0) continue;
        pair<int,int> p(bx+dx,by+dy);
        if (!buckets.count(p)) continue;
        REP(i,SIZE(buckets[p])) cand.push_back( buckets[p][i] );
      }
      REP(i,SIZE(it->second)) {
        double toto;
        FOR(j,SIZE(it->second),SIZE(cand)-1) {
          toto = size( P[cand[i]] - P[cand[j]] );
          if (2*toto >= result) continue;
          FOR(k,0,SIZE(cand)-1) {
            if (k==i) continue;
            if (k==j) continue;
            double toto2 = toto + size( P[cand[i]] - P[cand[k]] ) + size( P[cand[j]] - P[cand[k]] );
            result = min( result, toto2 );
          }
        }
      }
      /*
      REP(i,SIZE(it->second)) REP(k,i) {
        FOR(j,SIZE(it->second),SIZE(cand)-1) {
          double toto2 = size( P[cand[i]] - P[cand[j]] ) + size( P[cand[i]] - P[cand[k]] ) + size( P[cand[j]] - P[cand[k]] );
          result = min( result, toto2 );
        }
      }
      */
    }


    printf("Case #%d: %.12f\n",t,result);
    /*
    poly Q = convex_hull(P);
    if (SIZE(Q) == 1) {
      printf("Case #%d: 0\n",t);
      continue;
    }
    if (SIZE(Q) == 2) {
      DEBUG(Q[0]);
      DEBUG(Q[1]);
      printf("Case #%d: %.12f\n",t,2*sqrt(size(Q[0]-Q[1])));
      continue;
    }
    double ans = 1e30;
    REP(i,SIZE(Q)) REP(j,i) REP(k,j) {
      poly PA = intersect_line_line( Q[i], Q[(i+1)%N], Q[j], Q[(j+1)%N] );
      poly PB = intersect_line_line( Q[i], Q[(i+1)%N], Q[k], Q[(k+1)%N] );
      poly PC = intersect_line_line( Q[k], Q[(k+1)%N], Q[j], Q[(j+1)%N] );
      if (SIZE(PA)!=1) continue;
      if (SIZE(PB)!=1) continue;
      if (SIZE(PC)!=1) continue;
      point u = PB[0] - PA[0], v = PC[0] - PA[0];
      double toto = abs(0.5*cross_product(u,v));
      ans = min(ans,toto);
    }
    */
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
