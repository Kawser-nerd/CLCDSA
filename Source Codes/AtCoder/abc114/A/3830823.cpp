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
  int x;
  cin >> x;
  if (x == 3 || x == 5 || x == 7)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}