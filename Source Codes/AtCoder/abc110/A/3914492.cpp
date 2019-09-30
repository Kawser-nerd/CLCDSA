#include <iostream>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  cout << max({A, B, C}) * 9 + A + B + C << endl;
  return 0;
}