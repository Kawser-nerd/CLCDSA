#include <iostream>

using namespace std;

int main() {
  string s;
  int n;
  cin >> s >> n;
  int m = n - 1;
  cout << s.at(m / 5) << s.at(m % 5) << endl;
}