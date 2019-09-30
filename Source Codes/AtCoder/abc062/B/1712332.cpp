#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <map>
#include <set>
#define pi 3.1415926

using namespace std;

int main()
{
	int ht, wd;
	while (cin >> ht >> wd)
	{
		vector<string> v;
		for (int i = 0; i < ht; i++)
		{
			string t;
			cin >> t;
			v.push_back(t);
		}
		string s = "", ans = "";
		s += "#";
		s += string(wd, '#');
		s += "#";
		s += "\n";
		ans += s;
		for (int i = 0; i < ht; i++)
		{
			s = "";
			s += "#";
			s += v[i];
			s += "#";
			s += "\n";
			ans += s;
		}
		s = "";
		s += "#";
		s += string(wd, '#');
		s += "#";
		s += "\n";
		ans += s;
		cout << ans << flush;
	}
	return 0;
}