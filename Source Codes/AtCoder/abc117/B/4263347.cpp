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
  int l[10];
  cin >> n;
  REP(i, n)
  {
    cin >> l[i];
  }

  sort(l, l + n);
  int sum = 0;
  REP(i, n - 1)
  {
    sum += l[i];
  }

  if (l[n - 1] < sum)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}