#define _USE_MATH_DEFINES
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include <iostream>

using namespace std;

int main() {
  std::string str;
  cin >> str;
  if (str.back() == 'T')std::cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}