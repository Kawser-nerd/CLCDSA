#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int n;
int a[40];
int b[40];
int c[20];

stack<int> up;
stack<int> down;

int ret;

void rec( int i, int max_up, int max_down ) {
   if( i == 2*n ) {
      ret = min( ret, max_up + max_down - 2 );
      return;
   }

   if( b[i] == 0 ) {
      if( c[a[i]] < up.top() ) {
         up.push( c[a[i]] );
         rec( i+1, max( (int)up.size(), max_up ), max_down );
         up.pop();
      }
      if( c[a[i]] < down.top() ) {
         down.push( c[a[i]] );
         rec( i+1, max_up, max( (int)down.size(), max_down ) );
         down.pop();
      }
   } else {
      if( up.top() == i ) {
         up.pop();
         rec( i+1, max_up, max_down );
         up.push( i );
      }
      if( down.top() == i ) {
         down.pop();
         rec( i+1, max_up, max_down );
         down.push( i );
      }
   }
}

int main( void ) {
   int T;
   cin >> T;
   
   up.push( 1000000 );
   down.push( 1000000 );
   for( int tt = 1; tt <= T; ++tt ) {
      cin >> n;
      map<string,int> m;
      for( int i = 0, j = 0; i < 2*n; ++i ) {
         string s;
         cin >> s;
         if( !m.count( s ) ) {
            m[s] = j++;
            b[i] = 0;
         } else {
            c[m[s]] = i;
            b[i] = 1;
         }
         a[i] = m[s];
      }

      ret = 2*n;
      rec( 0, 1, 1 );

      if( ret == 2*n ) ret = -1;
      cout << "Case #" << tt << ": " << ret << endl;
   }

   return 0;
}
