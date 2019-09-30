#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;
  map<char, vector<string>> mp;

  int sLength = s.size();
  for (int i = 0; i < sLength; ++i)
  {
    vector<string> tmp;
    for (int j = 0; j < 5; ++j)
    {
      mp[s[i]].push_back(s.substr(i, j + 1));
    }
  }
  int count = 0;
  k--;

  for (auto pair : mp)
  {
    std::sort(mp[pair.first].begin(), mp[pair.first].end());
    std::vector<string>::iterator new_end = std::unique(mp[pair.first].begin(), mp[pair.first].end());
    mp[pair.first].erase(new_end, mp[pair.first].end());

    if (count <= k && k < count + mp[pair.first].size())
    {
      cout << mp[pair.first][k - count] << endl;
      return 0;
    }
    else
    {
      count += mp[pair.first].size();
    }
  }

  return 0;
}