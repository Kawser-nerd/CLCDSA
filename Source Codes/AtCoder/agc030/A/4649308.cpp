#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
#define ll long long int
int main(){
  int a,b,c,ans;
  cin >> a >> b >> c;

  if( c <= b ) 
  {
    ans = b + c;  
  } 
  else if ( ( c - b ) <= a ) 
  {
    ans = b + c;  
  }
  else 
  {
    ans = 2 * b + a + 1;  
  }
  cout << ans << endl;
  return 0;
}