#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#define int long long
using namespace std;
signed main() {
	string s; cin >> s;
	stack<char>st;
	for (int i = 0; i < s.size(); i++) {
		if (st.size() == 0 || st.top() == s[i])st.push(s[i]);
		else st.pop();
	}
	cout << s.size() - st.size() << endl;
}