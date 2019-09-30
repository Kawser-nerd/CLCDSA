#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int main()
{
  string s;
  cin >> s;
  int result = 753;
  for(int i = 0; i < s.size(); i++)
  {
    string temp;
    for(int j = i; j < i + 3; j++)
    {
      temp.push_back(s[j]);
    }
    int diff = stoi(temp);
    diff = abs(753 - diff);
    result = min(result, diff);
  }
  cout << result << endl;
	return 0;
}