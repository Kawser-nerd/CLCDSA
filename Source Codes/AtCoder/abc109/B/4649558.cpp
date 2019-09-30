#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
#define ll long long int

void ans ( bool ok ) {
  if ( ok == true ) cout << "Yes" << endl;
  else cout << "No" << endl;  
}

int main() {
  int n;
  cin >> n;
  vector < string > w(n);
  for ( int i = 0; i < n; ++i ) {
    cin >> w[i];  
  }
  bool ok = true;
  for ( int i = 0; i < n; ++ i ) {
    if ( i == 0 ) continue;
    int n = w[i - 1].length();
    if ( w[i - 1][n - 1] != w[i][0] ) ok = false;
    //cout << "??????" << w[i - 1][n - 1] << endl;
    //cout << "?????" << w[i][0] << endl;
  }
  //cout << ok << endl;
  for ( int i = 0; i < n; ++i ) {
    for ( int j = 0; j < n; ++j ) {
      if ( i == j ) continue;
      if( w[i] == w[j] ) 
      {
        ok = false;  
        //cout << "w[" << i << "] = " << w[i] << endl;
        //cout << "w[" << j << "] = " << w[j] << endl;
      }
    } 
  }
  ans( ok );
  return 0;
}