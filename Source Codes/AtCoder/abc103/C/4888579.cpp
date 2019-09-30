#include <iostream> 
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <fstream>
using namespace std;
#define ll long long int

int main( int argc, char *argv[] ) {
  int n,ans = 0;
  cin >> n;
  for ( int i = 0; i < n; i++ ) {
    int a;cin >> a;
    ans += a;
  }
  cout << ans - n<< endl;
  return 0;
}