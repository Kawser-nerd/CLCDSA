//I Guds namn
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	char ch;
	int pos, ans = 1000, cans = 1000, n = s.size();
	for(int i = 0;i < 26;i++)
	{
		ch = (char)('a' + i);
		pos = -1;
		cans = 0;
		for(int j = 0;j < s.size();j++)
			if(s[j] == ch)
			{
				cans = max(cans, j - pos - 1);
				pos = j;
			}
		cans = max(cans, n - 1 - pos);
		ans = min(ans, cans);
	}
	cout << ans << endl;
	return 0;
}