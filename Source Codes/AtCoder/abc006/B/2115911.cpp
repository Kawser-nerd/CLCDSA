#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long trib[n];
  trib[0] = 0;
  trib[1] = 0;
  trib[2] = 1;
  int i;
  for (i = 3; i < n; ++i)
    trib[i] = (trib[i-1] + trib[i-2] + trib[i-3])%10007;

  cout << trib[n-1] << "\n";

  return 0;
}