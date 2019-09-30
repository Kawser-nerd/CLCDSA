#include <iostream>

using namespace std;

int main() {
  int a, d;
  cin >> a >> d;
  if (a <= d) {
    ++a; 
  } else {
    ++d;
  }
  cout << a * d << endl;
}