#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size(), ans = 0, now = s[0] - '0';
	for (int i = 1; i < n; i += 2) {
		if (s[i] == '*') {
			now *= s[i - 1] - '0';
			now *= s[i + 1] - '0';
			if (now > 0)now = 1;
		}
		else if (s[i] == '+') {
			if (now > 0)ans++;
			now = s[i + 1] - '0';
		}
	}
	if (now > 0) ans++;
	cout << ans << endl;
}