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
  int h, w;
  cin >> h >> w;
  int c[10][10];
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      cin >> c[i][j];
  int a[h][w];
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> a[i][j];

  bool isMin[10] = {};
  isMin[1] = true;
  int mincount = 1;
  while (true)
  {
    int mini = -1, min = 10000;
    for (int i = 0; i < 10; i++)
    {
      if (!isMin[i] && (c[i][1] < min))
      {
        mini = i;
        min = c[i][1];
      }
    }
    isMin[mini] = true;
    mincount++;

    for (int i = 0; i < 10; i++)
    {
      c[i][1] = MIN(c[i][1], c[i][mini] + c[mini][1]);
    }

    if (mincount == 10)
      break;
  }

  int ans = 0;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (a[i][j] != -1)
      {
        ans += c[a[i][j]][1];
      }
    }
  }
  cout << ans << endl;
  return 0;
}