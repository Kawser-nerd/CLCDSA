#include <iostream>
using namespace std;

bool ATGC( char x ) {
  if (x == 'A' || x == 'T' || x == 'G' || x == 'C' ){
    return true;  
  } else {
    return false;  
  }
}
int main () {
  int ans = 0,temp = 0;
  string s;
  cin >> s;
  for ( auto c : s ) {
    if ( ATGC(c) ) ans = max( ans, ++temp );  
    else temp = 0;
  }
  cout << ans << endl;
  return 0;
}