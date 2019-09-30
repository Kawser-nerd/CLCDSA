#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string s[2], t[2];

	cin >> s[0] >> s[1];

	t[0] = s[1];
	t[1] = s[0];

	reverse(t[0].begin(), t[0].end());
	reverse(t[1].begin(), t[1].end());

	if (t[0] == s[0] && t[1] == s[1]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}