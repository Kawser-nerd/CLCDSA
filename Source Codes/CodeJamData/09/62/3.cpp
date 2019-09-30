#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define MAX 1000000
#define ITER 35
#define NEAR 40

int n;
struct point {
   double x, y;
} a[MAX];
const double pi = acos(-1.0);

double A, B;

bool cmp( const point &P, const point &Q ) {
   return P.x*A + P.y*B < Q.x*A + Q.y*B;
}

inline double dist( int i, int j ) {
   double dx = a[i].x - a[j].x;
   double dy = a[i].y - a[j].y;
   return sqrt( dx*dx+dy*dy );
}

int main( void ) {
   int T;
   cin >> T;
   for( int tt = 1; tt <= T; ++tt ) {
      cin >> n;
      for( int i = 0; i < n; ++i ) {
         cin >> a[i].x >> a[i].y;
      }

      double ret = 1e15;

      for( int it = 0; it < ITER; ++it ) {
         double alpha = pi * (double)it/ITER;
         
         A = sin( alpha );
         B = cos( alpha );

         sort( a, a+n, cmp );

         for( int i = 0; i < n; ++i ) {
            int up = min(n-i, NEAR);
            for( int j = 1; j < up; ++j )
               for( int k = j+1; k < up; ++k ) 
                  ret = min( ret, dist(i,i+j) + dist(i+j,i+k) + dist(i+k,i) );
         }
      }
      printf( "Case #%d: %.15lf\n", tt, ret );
      fprintf( stderr, "Case #%d: %.15lf\n", tt, ret );
      fprintf( stderr, "time %.5lf\n", clock() / (double)CLOCKS_PER_SEC );
   }
   
   return 0;
}
