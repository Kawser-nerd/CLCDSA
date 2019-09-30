#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, s;
	cin >> a;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == 'B')
		{
			if (!s.empty())
				s.pop_back();

		}
		else
			s.push_back(a[i]);
	}
	cout << s << endl;
	return 0;
}