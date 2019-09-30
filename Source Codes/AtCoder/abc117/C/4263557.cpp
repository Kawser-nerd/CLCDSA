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
  int n, m;
  int x[100000];
  int y[100000];

  cin >> n >> m;
  REP(i, m)
  {
    cin >> x[i];
  }

  if (n >= m)
  {
    cout << 0 << endl;
    return 0;
  }
  sort(x, x + m);
  REP(i, m - 1)
  {
    y[i] = x[i + 1] - x[i];
  }
  sort(y, y + m - 1);
  int result = 0;
  REP(i, m - n)
  {
    result += y[i];
  }

  cout << result << endl;
}