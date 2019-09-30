#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
using namespace std;
int main(void) {
  int n, k;
  cin >> n >> k;
  if (n % k)
    cout << 1;
  else
    cout << 0;
  cout << endl;

  return 0;
}