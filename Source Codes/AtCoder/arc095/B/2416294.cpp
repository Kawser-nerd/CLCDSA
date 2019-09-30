#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
using llint = long long int;
int n;
vector<int> va;
using vecitr = vector<int>::iterator;

int nearest(vecitr begin, vecitr end, int x)
{
  bool first = true;
  for (; begin != end; begin++)
  {
    if (*begin >= x)
    {
      int res = *begin;
      if (!first)
      {
        int diff = res - x;
        if (diff > x - *(begin - 1))
        {
          res = *(begin - 1);
        }
      }
      return res;
    }
    first = false;
  }
  return *(end - 1);
}

int main()
{
  cin >> n;
  va.reserve(n);
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    va.push_back(a);
  }
  sort(va.begin(), va.end());

  llint max = 0;
  pair<int, int> ans;
  int b = nearest(va.begin(), va.end() - 1, va.back() / 2);
  cout << va.back() << " " << b << endl;
  return 0;
}