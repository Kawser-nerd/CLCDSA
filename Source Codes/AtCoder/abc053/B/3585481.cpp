#include <iostream>
#include <math.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  auto begin = s.find_first_of('A');
  auto end = s.find_last_of('Z');
  cout << end - begin + 1 << '\n';
  return 0;
}