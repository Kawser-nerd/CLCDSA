#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
#define ll long long int
int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  if ( k % 2 == 1 ) cout << - a + b << endl;
  else cout << a - b << endl;  
  return 0;
}