#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  if (N == 1) {
    cout << "Hello World" << endl;
  } else if (N == 2) {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
  }

  return 0;
}