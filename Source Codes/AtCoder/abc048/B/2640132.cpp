#include <iostream>
using namespace std;

int main()
{
  long long a, b, x;

  cin >> a >> b >> x;

  if( a == 0 ) {
    cout << b / x + 1 << endl;
  }
  else {
    cout << b / x - ( a - 1 ) / x << endl;
  }

  return 0;
}