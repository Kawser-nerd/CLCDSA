#include<iostream>
#include<string>
using namespace std;
int main() {
	string s; cin >> s;
	if (s == "zyxwvutsrqponmlkjihgfedcba")puts("-1");
	else if (s.size() == 26) {
		for (int i = 25; i >= 0; i--) {
			if (s[i] > s[i - 1]) {
				for (int j = 25; j > i; j--) {
					if (s[j] > s[i - 1]) {
						cout << s.substr(0, i - 1) << s[j] << endl;
						return 0;
					}
				}
				if (i == 1)cout << s[i] << endl;
				else cout << s.substr(0, i - 1) << s[i] << endl;
				return 0;
			}
		}
	}
	else {
		for (char c = 'a'; c <= 'z'; c++) {
			for (int i = 0; i < s.size(); i++) {
				if (c == s[i])goto heaven;
			}
			cout << s << c << endl;
			return 0;
		heaven:;
		}
	}
	return 0;
}