#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	int j = 0;
	int check[114514];
	bool b = true;

	cin >> s;

	for (int i = s.length()-1; i >= 0; i--)
	{
		if (s[i] == s[j] || s[i] == '*' || s[j] == '*') {
			check[j] = 1;
		}
		else {
			check[j] = 0;
		}
		j++;
	}
	
	for (int i = 0; i < s.length(); i++)
	{
		if (check[i] == 0) {
			b = false;
		}
	}

	if (b) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	};
}