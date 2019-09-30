// AGC22-A-cpp.cpp : ????????????? ???????????
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;
int main()
{
	string s;
	cin >> s;
	unordered_map<char, bool> m;
	for (size_t i = 0; i < 26; i++)
	{
		m['a' + i] = true;
	}
	for (size_t i = 0; i < s.size(); i++)
	{
		m[s[i]] = false;
	}
	if (s.size() < 26)
	{	
		for (size_t i = 0; i < 26; i++)
		{
			if (m['a' + i])
			{
				cout << s << char('a' + i) << endl;
				return 0;
			}
		}
	}
	else {
		for (size_t i = 25; i > 0; i--)
		{
			if (s[i] > s[i-1])
			{
				char q = s[i];
				for (auto ss : s.substr(i))
				{
					if (ss > s[i-1]) q = ss < q ? ss : q;
				}
				cout << s.substr(0, i-1) << q << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;

    return 0;
}