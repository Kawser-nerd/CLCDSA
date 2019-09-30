#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX(a, b) ((a) < (b) ? (b) : (a))
using namespace std;
int main()
{
  int n;
  cin >> n;
  int f[n][10];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 10; j++)
      cin >> f[i][j];
  int p[n][11];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 11; j++)
      cin >> p[i][j];

  int maxprofit = -2147483647;
  for (int sched = 1; sched < 1024; sched++)
  {
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
      int c = 0;
      for (int j = 0; j < 10; j++)
      {
        if ((sched & (1 << j)) && f[i][j])
        {
          c++;
        }
      }
      profit += p[i][c];
    }
    maxprofit = MAX(profit, maxprofit);
  }
  cout << maxprofit << endl;
  return 0;
}