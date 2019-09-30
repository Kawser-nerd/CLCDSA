#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long int
int main(){
  ll n, m, ans = 0;
  cin >> n >> m;
  vector < pair< ll, ll > > a(n);
  for ( int i = 0; i < n; ++i ) {
    cin >> a[i].first >> a[i].second;  
  }
  sort ( a.begin(), a.end() );
  for ( int i = 0; i < n; ++i ) {
    //cout << "-------------" << endl;
    //cout << "??"  << m << "???????" << endl;
    //cout << "??" << a[i].first << "???????????????" << endl;
    //cout << a[i].second << "??????????" << endl;
    
    m -= a[i].second;
    if ( m >= 0) {
      ans += a[i].second * a[i].first;
    } else {
      m += a[i].second;
      ans += m * a[i].first;
      break;  
    }
    //cout << ans << "??????" << endl;
  }
  cout << ans << endl;

  
  return 0;
}