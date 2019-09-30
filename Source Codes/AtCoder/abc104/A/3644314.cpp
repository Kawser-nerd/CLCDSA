#include <iostream>
using namespace std;

int main() {
  int R;
  cin >> R;

  if (R < 1200) {
    cout << "ABC" << endl;
  } else if (R < 2800) {
    cout << "ARC" << endl;
  } else {
    cout << "AGC" << endl;
  }
  return 0;
}