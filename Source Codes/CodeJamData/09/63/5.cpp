#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 10007;

int R, C;
char a[4][5];

int memo[4][4][26*26*26*26];

int rec( int r, int c ) {
   if( r == R ) return 1;
   if( c == C ) return rec( r+1, 0 );

   int state = 0;
   for( int cc = 0; cc < C; ++cc ) {
      int rr = cc < c ? r : r-1;
      if( rr >= 0 ) state = state*26 + a[rr][cc] - 'a';
   }
   
   int &ret = memo[r][c][state];
   if( ret >= 0 ) return ret;

   ret = 0;
   
   char L = c == 0 ? 'a' : a[r][c-1];
   char U = r == 0 ? 'a' : a[r-1][c];

   bool dot = a[r][c] == '.';

   for( char ch = max( L, U ); ch <= 'z'; ++ch ) {
      if( !dot && a[r][c] != ch ) continue;
      a[r][c] = ch;
      ret += rec( r, c+1 );
      if( ret >= MOD ) ret -= MOD;
   }
   if( dot ) a[r][c] = '.';

   return ret;
}

int main( void ) {
   int T;
   cin >> T;
   for( int tt = 1; tt <= T; ++tt ) {
      cin >> R >> C;
      for( int r = 0; r < R; ++r ) 
         cin >> a[r];

      memset( memo, -1, sizeof memo );

      cout << "Case #" << tt << ": " << rec(0,0) << endl;
   }
   
   return 0;
}
