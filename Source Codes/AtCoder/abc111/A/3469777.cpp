#include <iostream>
#include <string>
using namespace std;
int main(void) {
  string num;
  cin >> num;
  for(int tmp= 0; tmp < 3; tmp++) {
    if (num.at(tmp) == '1') {
      cout << 9;
    }
    else if (num.at(tmp) == '9') {
      cout << 1;
    }
  }
  cout << endl;
  return 0;
}