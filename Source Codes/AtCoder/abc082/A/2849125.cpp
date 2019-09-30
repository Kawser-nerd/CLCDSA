#include <iostream>

using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  int ave = (a + b) / 2;
  if ((a + b) % 2 == 0) cout << ave << endl;
  else                  cout << ave + 1 << endl;
  return 0;
}