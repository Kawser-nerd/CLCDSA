#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;

  int m[n];
  int min_m = INT_MAX;

  for (int i = 0; i < n; i++) {
    cin >> m[i];
    // ?????????????????????????
    if (m[i] < min_m) min_m = m[i];
    x -= m[i];
  }

  cout << n + x / min_m << endl;

  return 0;
}