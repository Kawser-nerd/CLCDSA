#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  int sum = 700;
  for (auto c : S) {
    if (c == 'o') sum += 100;
  }

  cout << sum << '\n';
  return 0;
}