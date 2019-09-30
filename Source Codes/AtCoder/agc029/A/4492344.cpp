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
  string s;
  ll c = 0, result = 0;
  cin >> s;
  REP(i, s.length())
  {
    if (s[i] == 'B')
    {
      c++;
    }
    else
    {
      result += c;
    }
  }

  cout << result << endl;
}