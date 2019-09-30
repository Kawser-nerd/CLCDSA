#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(a*b, c*d);
  return 0;
}