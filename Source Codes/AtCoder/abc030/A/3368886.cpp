#include <iostream>

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (b * c > a * d) {
    cout << "TAKAHASHI";
  } else if (b * c < a * d) {
    cout << "AOKI";
  } else {
    cout << "DRAW";
  }
  cout << endl;
}