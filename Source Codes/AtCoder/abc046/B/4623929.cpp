#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define ll long long int

int main(){
  ll n,k;
  cin >> n >> k;

  ll ans = 1;
  for ( int i = 0; i < n; ++i ) {
    if ( i == 0) ans *= k;
    else ans *= ( k - 1 );
  }
  cout << ans << endl;
  return 0;
}