#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int sum = 0;
  for (int i = 1; i < b - a; i++) {
    sum += i;
  }
  cout << sum - a << endl;
  return 0;
}