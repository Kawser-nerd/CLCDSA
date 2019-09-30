#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <unordered_map>

#define REP(i, n) for (int i = 0; i < n; i++)
#define ll long long int

using namespace std;

int main()
{
  ll a, b, c;
  cin >> a >> b >> c;
  if (a + b + 1 >= c)
  {
    cout << b + c << endl;
  }
  else
  {
    cout << a + b + 1 + b << endl;
  }
}