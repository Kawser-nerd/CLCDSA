#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
#define ll long long int

int main() {
  string s;
  ll ans = 0, w = 0;
  cin >> s;
  for ( int i = 0; i < s.length(); ++i ) {
    if ( s[i] == 'W' ){
      ans += i - w;
      ++w;  
    }  
  }
  cout << ans << endl;
  return 0;
}