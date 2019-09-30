#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main ()
{
  int n, k, x, y;

  cin >> n;
  cin >> k;
  cin >> x;
  cin >> y;

  if (n - k > 0) {
    cout << k * x + (n - k) * y << endl;
  } else {
    cout << n * x << endl;
  }
}