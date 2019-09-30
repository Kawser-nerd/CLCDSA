#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;
int main()
{
  int n, c_;
  cin >> n >> c_;
  int s[n], t[n], c[n];
  const int TMAX = 100000 + 1;

  int tmp[c_][TMAX];
  for (int i = 0; i < c_; i++)
    for (int j = 0; j < TMAX; j++)
      tmp[i][j] = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> s[i] >> t[i] >> c[i];
    c[i]--;
    tmp[c[i]][s[i]]++;
    tmp[c[i]][t[i]]--;
  }

  int a[TMAX * 2 + 2];
  for (int i = 0; i < TMAX * 2 + 2; i++)
  {
    a[i] = 0;
  }

  for (int i = 0; i < c_; i++)
  {
    for (int j = 0; j < TMAX; j++)
    {
      if (tmp[i][j] == 1)
      {
        a[j * 2 - 1]++;
      }
      else if (tmp[i][j] == -1)
      {
        a[j * 2]--;
      }
    }
  }
  int ans = 0;
  for (int i = 0, s = 0; i < TMAX * 2 + 2; i++)
  {
    s += a[i];
    ans = MAX(ans, s);
  }
  cout << ans << endl;
  return 0;
}