#include <iostream>
using namespace std;

int main() {
  char str[11];
  cin >> str;
  str[3] = '8';
//  str[10] = '\n';
//  str[11] = '\0';
  cout << str << '\n';
  return 0;
}