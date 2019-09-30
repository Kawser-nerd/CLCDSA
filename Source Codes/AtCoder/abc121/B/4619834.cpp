#include <iostream>
#include <vector>

using namespace std;
#define ll long long int
int main(){
  int n, m, c;
  cin >> n >> m >> c;
  int b[m];
  int a[n][m];
  for ( int i = 0; i < m; ++i ) cin >> b[i];
  
  for ( int i = 0; i < n; ++i ) {
    for ( int j = 0; j < m; ++j ) {
      cin >> a[i][j];  
    }  
  }

  int ans = 0;
  for ( int i = 0; i < n; ++i ) {
    int temp = c;
    for ( int j = 0; j < m; ++j ) {
      temp += a[i][j] * b[j]; 
    }
    if ( temp > 0) ++ans;
  }
  cout << ans << endl;
  
  return 0;
}