#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int sc = 0;
	int m = 0, u = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')sc++;
		else sc--;

		if (sc < 0)m++, sc++;
	}
	u += sc;
	for (int i = 0; i < m; i++)cout << '(';
	cout << s;
	for(int i=0;i<u;i++)cout << ')';
	cout << endl;
}