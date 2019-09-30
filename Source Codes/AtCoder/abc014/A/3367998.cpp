#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  cout << (b - a % b) % b << endl;
}