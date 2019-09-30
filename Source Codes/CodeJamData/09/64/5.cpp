#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int oo = 1000000;
const int M = 1000;

int n;
int x[500], y[500], r[500], s[500];

inline bool in_range( int i, int j ) {
   return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) <= r[i]*r[i];
}

int c[502][502];
int ff[502];
int bio[502];
int how[502];

int bfs( int source, int sink ) {
   for( int i = 0; i < n+2; ++i ) { 
      bio[i] = 0; 
      how[i] = -1; 
      ff[i] = 0; 
   }

   queue<int> Q;
   bio[source] = 1;
   ff[source] = oo;
   Q.push( source );
   while( !Q.empty() ) {
      int x = Q.front(); Q.pop();
      bio[x] = 2;

      if( x == sink ) return ff[x];

      for( int y = 0; y < n+2; ++y ) {
         if( !c[x][y] || bio[y] == 2 ) continue;
         int f = min( ff[x], c[x][y] );
         if( f <= ff[y] ) continue;
         ff[y] = f;
         how[y] = x;
         if( bio[y] == 0 ) {
            bio[y] = 1;
            Q.push( y );
         }
      }
   }
   return 0;
}

int min_cut( int source, int sink ) {
   int flow = 0;
   for( int f; (f = bfs( source, sink )); flow += f ) {
      for( int x = sink; x != source; x = how[x] ) {
         c[how[x]][x] -= f;
         c[x][how[x]] += f;
      }
   }
   return flow;
}

int main( void ) {
   int T;
   cin >> T;
   for( int tt = 1; tt <= T; ++tt ) {
      cin >> n;
      for( int i = 0; i < n; ++i ) 
         cin >> x[i] >> y[i] >> r[i] >> s[i];      

      memset( c, 0, sizeof c );

      int source = n;
      int sink = n+1;

      for( int i = 0; i < n; ++i ) {
         for( int j = 0; j < n; ++j )
            if( in_range( i, j ) )
               c[i][j] = oo;
         
         c[n][i] = M;
         c[i][n+1] = M - s[i];
      }
      
      cout << "Case #" << tt << ": " << n*M - min_cut(source, sink) << endl;
   }
   
   return 0;
}
