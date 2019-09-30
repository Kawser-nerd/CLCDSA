#include <iostream>
#include <vector>
using namespace std;
int n, x, sum = 0;
int main() {
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (x % 2 == 1)
      sum += a[i];
    x /= 2;
  }
  cout << sum << endl;
  return 0;
}