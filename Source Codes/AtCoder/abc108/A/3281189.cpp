#include <iostream>
using namespace std;
int main(void) {
  int k;
  cin >> k;
  int n = k % 2;
  int m = k / 2;
  if(n == 0) {
    cout << m * m << endl;
  }
  else {
    cout << m * (m + 1) << endl;
  }
  return 0;
}