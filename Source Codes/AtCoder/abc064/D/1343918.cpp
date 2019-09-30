//I Guds namn
#include <deque>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int sum = 0;
	deque<char> ans;
	for(int i = 0;i < n;i++)
	{
		ans.push_back(s[i]);
		sum += (s[i] == '(' ? 1 : -1);
		if(sum < 0)
		{
			ans.push_front('(');
			sum++;
		}
	}
	while(sum-- > 0)
		ans.push_back(')');
	for(auto &c : ans)
		cout << c;
	cout << endl;
	return 0;
}