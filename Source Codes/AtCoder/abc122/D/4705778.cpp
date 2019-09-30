#include <iostream> 
using namespace std;
#define ll long long 
const ll mod = 1e9 + 7;
ll substring_count[105][4][4][4];

void add( ll& a, ll& b ) {
  a = ( a + b ) % mod;
}

bool ng( int a, int b, int  c ) {
  if ( a == 1 && b == 2 && c == 3 ) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int n; cin >> n;
  substring_count[0][0][0][0] = 1;

  for ( int i = 0; i < n; ++i ) {
    for ( int a = 0; a < 4; ++a ) {
      for ( int b = 0; b < 4; ++b ) {
        for ( int c = 0; c < 4; ++c ) {
          for ( int d = 0; d < 4; ++d ) {
            
            
            if ( ng(b,c,d) || ng(c,b,d) || ng(b,d,c) ) continue;
            if ( ng(a,c,d) || ng(a,b,d) ) continue;
          
            add( substring_count[i + 1][b][c][d], substring_count[i][a][b][c] );
          }
        }
      }  
    }  
  }
  ll ans = 0;
  for ( int a = 0; a < 4; ++a ) {
    for ( int b = 0; b < 4; ++b ) {
      for ( int c = 0; c < 4; ++c ) {
        add( ans, substring_count[n][a][b][c] );  
      }
    }  
  }
  cout << ans << endl;
}