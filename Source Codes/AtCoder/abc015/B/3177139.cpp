#include <iostream>
using namespace std;
int main() {
  int n, a, sum = 0;
  cin >> n;
  int l = n;
  for (int i = 0; i < l; i++) {
    cin >> a;
    if (a == 0)
      n--;
    sum += a;
  }
  if (sum % n == 0)
    cout << sum / n;
  else
    cout << sum / n + 1;
  return 0;
}