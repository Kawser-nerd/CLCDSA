#include <iostream>
#include <stack>
using namespace std;
int main()
{
	string s;
	cin >> s;
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'T' && !st.empty() && st.top() == 'S')
			st.pop();
		else
			st.push(s[i]);
	}
	cout << st.size();
	return 0;
}