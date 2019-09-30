#include <iostream>
using namespace std;

int main() {
  char x, y;
  cin >> x >> y;
  cout << (x > y ? '>' : (x < y ? '<' : '=')) << endl;
  return 0;
}