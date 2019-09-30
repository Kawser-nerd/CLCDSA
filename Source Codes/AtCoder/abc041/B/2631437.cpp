#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  long long ans, x;
  x = pow( 10, 9 ) + 7;

  ans = a % x;
  ans = ans % x;
  ans = ans * ( b % x );
  ans = ans % x;
  ans = ans * ( c % x );
  ans = ans % x;

  cout << ans << endl;

  return 0;
}