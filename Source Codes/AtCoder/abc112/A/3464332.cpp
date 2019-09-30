#include <iostream>
using namespace std;
int main(void) {
  int a;
  cin >> a;
  if (a == 1) {
    cout << "Hello World" << endl;
  }
  else if (a == 2) {
    int x, y;
    cin >> x >> y;
    cout << x + y << endl;
  }
  return 0;
}