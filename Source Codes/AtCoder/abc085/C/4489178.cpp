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
  int n, y;
  cin >> n >> y;

  REP(i, n + 1)
  {
    REP(j, n + 1)
    {
      if (i + j > n)
      {
        continue;
      }
      if (10000 * i + 5000 * j + 1000 * (n - i - j) == y)
      {
        cout << i << " " << j << " " << n - i - j << endl;
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
}