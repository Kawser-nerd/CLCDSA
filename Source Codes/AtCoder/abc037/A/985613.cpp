#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;  
  cout << c / min({a, b}) << endl;
  return 0;
}