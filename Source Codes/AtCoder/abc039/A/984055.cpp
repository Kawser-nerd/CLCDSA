#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;  
  cout << (a * b + b * c + c * a) * 2 << endl;
  return 0;
}