#include <iostream>
using namespace std;

int main () {
  int a, b;
  cin >> a >> b;
  if (b >= 0 && a <= 0) {
    cout << "Zero" << endl;
    return 0;
  }
  if (a > 0) {
    cout << "Positive" << endl;
    return 0;
  }
  if (b < 0 && a < 0) {
  	if ((b - a) % 2 == 0) {
      cout << "Negative" << endl;
    }  
    else {
      cout << "Positive" << endl;
    }
  }
}