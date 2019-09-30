#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
int main() {
  int n;
  string s;
  cin >> n >> s;
  vector< ll > sum(26);
  for ( int i = 0; i < n; ++i ) {
    char x = s[i];
    for (int j = 0; j < 26; ++j){
      char y = 'a' + j;
      if ( x == y) ++sum[j];  
    }
  }
  ll ans = 1;
  for (int i = 0; i < 26; ++i){
    ans *= sum[i] + 1;
    ans %= mod;
  }
  cout << ans - 1 << endl;
  return 0;
}