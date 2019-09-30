#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int a, b, c, d; cin >> a >> b >> c >> d;
  int ans = max(a * b, c * d);

  cout << ans << endl;
  return 0;
}