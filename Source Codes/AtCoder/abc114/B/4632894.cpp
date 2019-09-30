#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
#define ll long long int

int main(){
  string s; 
  cin >> s;
  int ans = 1000;
  for ( int i = 0; i + 2 < s.length(); ++i ) {
    int temp = 0;
    temp += ( s[i] - '0' ) * 100 + ( s[i + 1] - '0' ) * 10 + s[i + 2] - '0' ;
    //cout << temp << endl;
    ans = min( ans , abs( temp - 753 ) );
  }
  cout << ans << endl;
  return 0;
}