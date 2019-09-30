#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
  int A, B;
  cin >> A >> B;
  if (A + B < 24) {
    cout << A + B << endl;
  } else {
    cout << A + B - 24 << endl;
  }
  return 0;
}