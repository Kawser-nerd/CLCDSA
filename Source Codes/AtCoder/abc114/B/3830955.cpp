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

int to_int(string s)
{
  return atoi(s.c_str());
}

int main()
{
  string s;
  cin >> s;
  int min = 100000;
  for (int i = 0; i < s.length() - 2; i++)
  {
    string sub = s.substr(i, 3);
    int tmp = abs(to_int(sub) - 753);
    if (tmp < min)
    {
      min = tmp;
    }
  }
  cout << min << endl;
}