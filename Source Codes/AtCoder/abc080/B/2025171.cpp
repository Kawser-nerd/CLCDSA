#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int m = n;
  int s = 0;
  while (m != 0)
  {
    s += m % 10;
    m /= 10;
  }
  cout << (n % s == 0 ? "Yes" : "No") << endl;
  return 0;
}