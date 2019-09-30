#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  int n, k;
  cin >> n >> k;
  int m = 1;
  for (int i = 0; i < n; i++)
  {
    if (m * 2 >= m + k)
    {
      m += k;
    }
    else
    {
      m *= 2;
    }
  }
  cout << m << endl;
  return 0;
}