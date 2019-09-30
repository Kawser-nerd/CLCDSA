#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
#define ll long long int
int main(){
  int n,k;
  cin >> n >> k;
  vector < ll > h(n);
  for ( int i = 0; i < n; ++i ) {
    cin >> h[i];  
  }
  sort( h.begin(), h.end() );
  ll ans = 1e9;
  for ( int i = 0; i < n - k + 1 ; ++i ) {
    ans = min ( ans, h[i + k - 1] - h[i] );  
  }
  cout << ans << endl;
  return 0;
}