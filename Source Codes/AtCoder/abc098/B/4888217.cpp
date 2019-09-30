#include <iostream> 
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <fstream>
using namespace std;
#define ll long long int

int main( int argc, char *argv[] ) {
  int n;cin >> n;
  string s;cin >> s;
  int ans = 0;
  for ( int i = 0; i < n; i++ ) {
    int temp = 0;
    for ( int j = 0; j < 26; ++j ) {
      char x = 'a' + j;
      //cout << x << endl;
      bool left = false, right = false;
      for ( int k = 0; k < i; k++ ) {
        if (s[k] == x) left = true;  
      }
      for ( int k = i; k < n; k++ ) {
        if (s[k] == x) right = true;  
      }
      if ( (left == true) && (right == true) )temp++;
    }
    ans = max(ans,temp);
    //cout << "when i is " << i << "," << endl;
    //cout << "ans is " << ans << endl;
    //cout << "temp is " << temp << endl;
  }

  cout << ans << endl;
  return 0;
}