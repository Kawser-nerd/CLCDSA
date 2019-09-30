#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int t = 1900 * m + 100 * (n - m);
  for (int i = 0; i < m; i++)
    t *= 2;
  cout << t << endl;
  return 0;
}