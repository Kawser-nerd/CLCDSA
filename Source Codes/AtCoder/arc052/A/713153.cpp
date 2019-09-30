#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	string s;
	cin >> s;
	vector <char> v;
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]))
		{
			v.push_back(s[i]);
		}
	for (auto x: v)
	{
		cout << x;
	}
	cout << endl;
    return 0;
}