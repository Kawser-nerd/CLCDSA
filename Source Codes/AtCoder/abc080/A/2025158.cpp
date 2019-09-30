#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  cout << ((a * n < b) ? a * n : b) << endl;
  return 0;
}