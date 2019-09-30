#include <vector>
#include <string>
#include <iostream>
using namespace std;
string next_str(string s) {
	vector<bool> used(26);
	for (int i = 0; i < s.size(); ++i) {
		used[s[i] - 'a'] = true;
	}
	for (char i = s.back() + 1; i <= 'z'; ++i) {
		if (!used[i - 'a']) {
			s.back() = i;
			return s;
		}
	}
	return "-1";
}
int main() {
	string s;
	cin >> s;
	if (s.size() != 26) {
		vector<bool> used(26);
		for (int i = 0; i < s.size(); ++i) {
			used[s[i] - 'a'] = true;
		}
		for (int i = 0; i < 26; ++i) {
			if (!used[i]) {
				cout << s + (char)(i + 'a') << endl;
				break;
			}
		}
	}
	else {
		string ans = "-1";
		for (int i = s.size(); i >= 1 && ans == "-1"; --i) {
			ans = next_str(s.substr(0, i));
		}
		cout << ans << endl;
	}
	return 0;
}