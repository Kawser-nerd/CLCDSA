#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  if (n < 1200)
    cout << "ABC";
  else if (n < 2800)
    cout << "ARC";
  else
    cout << "AGC";
  cout << endl;
  return 0;
}