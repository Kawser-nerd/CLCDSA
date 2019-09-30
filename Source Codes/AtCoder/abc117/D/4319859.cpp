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
  int n;
  ll k;
  ll a[100000];
  ll result = 0;
  ll mask = 1;

  ll list0[40];
  ll list1[40];

  cin >> n >> k;
  k++;
  REP(i, n)
  {
    cin >> a[i];
  }

  REP(j, 40)
  {

    int on = 0;
    int off = 0;

    REP(i, n)
    {
      if (a[i] & (mask << j))
      {
        on++;
      }
      else
      {
        off++;
      }
    }

    list0[j] = (mask << j) * off;
    list1[j] = (mask << j) * on;
  }

  REP(i, 40)
  {
    if (!(k & (mask << i)))
    {
      continue;
    }
    ll tmp = 0;
    {
      for (int j = 39; j > i; j--)
      {
        if (k & (mask << j))
        {

          tmp += list0[j];
        }
        else
        {
          tmp += list1[j];
        }
      }

      tmp += list1[i];

      for (int j = 0; j < i; j++)
      {
        if (list0[j] < list1[j])
        {
          tmp += list1[j];
        }
        else
        {
          tmp += list0[j];
        }
      }

      if (result < tmp)
      {
        result = tmp;
      }
    }
  }

  cout << result << endl;
}