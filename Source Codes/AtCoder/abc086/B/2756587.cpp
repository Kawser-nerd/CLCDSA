#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  string c = a + b;
  int num = std::atoi(c.data());
  for (int i = 4; i * i <= num; ++i) {
    if (i * i == num) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}