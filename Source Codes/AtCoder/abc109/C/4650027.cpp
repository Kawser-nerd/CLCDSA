#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
#define ll long long int


ll gcd ( ll a, ll b ) {
  if ( a % b == 0 ) return b;
  else {
    return ( gcd( b, a % b ) );  
  }  
}
int main() {
  ll n, x, ans;
  cin >> n >> x;
  vector < ll > h(n);
  for ( int i = 0; i < n; ++i ) {
    cin >> h[i];
    if( h[i] - x != 0 ) {
      ans = abs( h[i] - x );  
    }  
  }

  for ( int i = 0; i < n; ++i ) {
    if ( h[i] == x ) continue;
    ll diff = abs( h[i] - x );
    ans = gcd ( ans, diff );  
  }

  cout << ans << endl;
  return 0;
}