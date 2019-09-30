#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

const int TRUE = 1;
const int FALSE = 0;

const int NORTH = 0, SOUTH = 1;
const int WEST = 0, EAST = 1;

typedef struct {
     int x;
     int y;
} point;

typedef struct {
     int row;
     int col;
     int sn;
     int ew;
} info;

info get_info(point p) {
     info f;
     f.row = p.x/2;
     f.col = p.y/2;
     f.sn = p.x%2;
     f.ew = p.y%2;
     return f;
}

int is_same_street(point p0, point p1) {
     if ( p0.x / 2 != p1.x / 2 ) {
	  return FALSE;
     }
     if ( p0.y / 2 != p1.y / 2 ) {
	  return FALSE;
     }
     return TRUE;
}

int S[20][20];
int W[20][20];
int T0[20][20];

int street_crossing(point p0, point p1, int t) {
     assert( is_same_street(p0, p1) );
     int row = p0.x / 2;
     int col = p0.y / 2;
     int p = S[row][col] + W[row][col];
     int s0 = (T0[row][col]) % p;
     int s1 = (T0[row][col] + S[row][col]) % p;
     int w0 = (T0[row][col] + S[row][col]) % p;
     int w1 = (T0[row][col] + S[row][col] + W[row][col]) % p;

     int next;
     if ( p0.x == p1.x ) { // WEST - EAST
	  t %= p;
	  if ( w0 < w1 ) {
	       if ( w0 <= t && t < w1 ) {
		    return 1;
	       }
	       else {
		    next = w0;
	       }
	  }
	  else {
	       if ( w0 <= t || t < w1 ) {
		    return 1;
	       }
	       else {
		    next = w0;
	       }
	  }
     }
//     if ( p0.y == p1.y ) { // SOUTH - NORTH
     else {
	  t %= p;
	  if ( s0 < s1 ) {
	       if ( s0 <= t && t < s1 ) {
		    return 1;
	       }
	       else {
		    next = s0;
	       }
	  }
	  else {
	       if ( s0 <= t || t < s1 ) {
		    return 1;
	       }
	       else {
		    next = s0;
	       }
	  }
     }

     if ( next < t ) {
	  next += p;
     }

     return next - t + 1;
}

int dist(point p0, point p1, int t) {
     if ( p0.x == p1.x ) {
	  if ( p0.y + 1== p1.y ) {
	       if ( !is_same_street(p0, p1) ) {
		    return 2;
	       }
	       else {
		    return street_crossing(p0, p1, t);
	       }
	  }
	  else if ( p0.y - 1 == p1.y ) {
	       if ( !is_same_street(p0, p1) ) {
		    return 2;
	       }
	       else {
		    return street_crossing(p0, p1, t);
	       }
	  }
     }
     else if ( p0.y == p1.y ) {
	  if ( p0.x + 1== p1.x ) {
	       if ( !is_same_street(p0, p1) ) {
		    return 2;
	       }
	       else {
		    return street_crossing(p0, p1, t);
	       }
	  }
	  else if ( p0.x - 1 == p1.x ) {
	       if ( !is_same_street(p0, p1) ) {
		    return 2;
	       }
	       else {
		    return street_crossing(p0, p1, t);
	       }
	  }
     }
     return -1;
}

int opt[40][40];
int M, N;

int valid(int i, int j) {
     return 0 <= i && i < 2*M && 0 <= j && j < 2*N;
}

void f(void) {
     for ( int i = 0; i < 4*M*N-1; i++ ) {
	  int min_i = -1, min_j = -1, min_t = INT_MAX;
	  for ( int from_i = 0; from_i < 2*M; from_i++ ) {
	       for ( int from_j = 0; from_j < 2*N; from_j++ ) {
		    if ( opt[from_i][from_j] < 0 ) {
			 continue;
		    }
		    for ( int to_i = from_i-1; to_i <= from_i+1; to_i++ ) {
			 for ( int to_j = from_j-1; to_j <= from_j+1; to_j++ ) {
			      if ( !valid(to_i, to_j) ) {
				   continue;
			      }
			      if ( opt[to_i][to_j] >= 0 ) {
				   continue;
			      }
			      point p0, p1;
			      p0.x = from_i;
			      p0.y = from_j;
			      p1.x = to_i;
			      p1.y = to_j;
			      int d = dist(p0, p1, opt[from_i][from_j]);
			      if ( d < 0 ) {
				   continue;
			      }
			      assert(d > 0);
			      if ( opt[from_i][from_j] + d < min_t ) {
				   min_i = to_i;
				   min_j = to_j;
				   min_t = opt[from_i][from_j] + d;
			      }
			 }
		    }
	       }
	  }
	  assert(min_t > 0);
	  assert(valid(min_i, min_j));
	  assert(opt[min_i][min_j] < 0);
	  opt[min_i][min_j] = min_t;
     }
}

int main(void) {
     int C;

     scanf("%d", &C);

     for ( int test = 0; test < C; test++ ) {
	  scanf("%d %d", &M, &N);

	  for ( int i = 0; i < 2*M; i++ ) {
	       for ( int j = 0; j < 2*N; j++ ) {
		    opt[i][j] = -1;
	       }
	  }
	  opt[2*M-1][0] = 0;

	  for ( int i = 0; i < M; i++ ) {
	       for ( int j = 0; j < N; j++ ) {
		    scanf("%d %d %d", &S[i][j], &W[i][j], &T0[i][j]);
	       }
	  }

	  f();

	  printf("Case #%d: %d\n", test+1, opt[0][2*N-1]);
     }
     return 0;
}
